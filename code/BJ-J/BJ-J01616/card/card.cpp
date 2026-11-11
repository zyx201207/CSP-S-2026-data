#include<iostream>
using namespace std;
int n,m,a[500010],cnt[300010]={};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        bool hc[300010]={};
        int l=0,c[300010];
        for(int j=i;j<=n;j++)
        {
            if(hc[a[j]])
            {
                for(l=l;true;l--)
                {
                    if(c[l]==a[j])
                    {
                        break;
                    }
                    hc[c[l]]=false;
                }
                l--;
                hc[a[j]]=false;
            }
            hc[a[j]]=true;
            l++;
            c[l]=a[j];
        }
        for(int i=1;i<=m;i++)
        {
            if(hc[i])cnt[i]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
