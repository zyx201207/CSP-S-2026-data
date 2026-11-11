#include<iostream>
#include<algorithm>
using namespace std;
int a[500005];
int ans[500005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        int cnt=1;
        int yz[500005];
        int zm[500005];
        
        for(int j=i;j<=n;j++)
        {
            if(yz[a[j]]>0)
            {
                for(int k=yz[a[j]]+1;k<cnt;k++)
                {
                    yz[zm[k]]=0;
                    zm[k]=0;

                }
                cnt=yz[a[j]]+1;
            }
            else
            {
                zm[cnt]=a[j];
                yz[a[j]]=cnt;
                cnt++;
            }
        }
        for(int j=1;j<=m;j++)
        {
            ans[j]+=(yz[j]>0);
        }
        
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }

}
