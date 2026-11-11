#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int have[500005];
int ans;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int x=n,have_len=0,have_lost=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            have_len++;
            for(int k=1;k<=j;k++)
            {
                if(have[k]!=a[j]) have[j]=a[j];
                else
                {
                    for(int t=k;t<=have_len;t++)
                    {
                        have[t]=0;
                        have_lost++;
                    }
                    have_len-=have_lost;
                    have_lost=0;
                }
            }
        }
        for(int j=1;j<=have_len;j++)
        {
            if(have[j]==i) ans++;
            have[j]=0;
        }
        cout<<ans<<" ";
        ans=0;
    }
    return 0;
}

