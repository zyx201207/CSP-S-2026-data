//T4
#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010];
int pos[200010];
long long cnt[200010];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=m;i++)
    {
        cnt[i]=0;
        pos[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(pos[a[j]])
            {
                if(j!=pos[a[j]]+1)
                {
                    for(int k=1;k<=m;k++)
                    {
                        if(pos[k]>pos[a[j]]) pos[k]=0;
                    }
                }

            }
            pos[a[j]]=j;
        }
        for(int j=1;j<=m;j++)
        {
            if(pos[j]) cnt[j]++;
            pos[j]=0;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
