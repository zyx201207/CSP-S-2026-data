#include<bits/stdc++.h>
using namespace std;

#define int long long
#define dnl "\n"

const int MAXN=5e5+5;

int n,m;
int a[MAXN],b[MAXN];
int ans[MAXN];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        // cout<<b[i]<<" ";
    }

    // cout<<dnl;

    if(n>500)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                a[j]=b[j];
            }

            int tmp=a[i];
            for(int j=i+1;j<=n;j++)
            {
                if(tmp==a[j])
                {
                    continue;
                }

                else
                {
                    ans[tmp]+=1;
                    tmp=a[j];
                }
            }
        }
    }

    else
    {
        for(int i=1;i<=n;i++)
        {
        for(int j=i;j<=n;j++)
        {
            a[j]=b[j];
        }
        for(int j=i;j<=n;j++)
        {
            int tmp=a[j];

            if(tmp==0)
            {
                continue;
            }

            for(int k=j-1;k>=i;k--)
            {
                if(a[k]==tmp)
                {
                    for(int l=k;l<j;l++)
                    {
                        a[l]=0;
                    }
                    break;
                }
            }
        }

        // for(int j=i;j<=n;j++)
        // {
        //     cout<<a[i]<<" ";
        // }

        // cout<<dnl;

        for(int j=i;j<=n;j++)
        {
            if(a[j]==0)
            {
                continue;
            }
            ans[a[j]]++;
        }
    }
    }

    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}
