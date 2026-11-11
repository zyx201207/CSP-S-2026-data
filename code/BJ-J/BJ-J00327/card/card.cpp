#include <iostream>
#include <cstring>
using namespace std;
int a[500001];
int f[500001];
int ans[300001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int t=1;t<=n;t++)
    {
        memset(f,0,sizeof(f));
        int l=0;
        for(int i=t;i<=n;i++)
        {
            for(int j=1;j<=l;j++)
            {
                if(f[j]==a[i])
                {
                    l=j-1;
                    break;
                }
            }
            l+=1;
            f[l]=a[i];
        }
        for(int i=1;i<=l;i++)
        {
            ans[f[i]]+=1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
