#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int ans[N];
int pos[M];
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
        memset(pos,0,sizeof(pos));
        for(int j=i;j<=n;j++)
        {
            if(pos[a[j]]!=0)
            {
                for(int k=1;k<=m;k++)
                {
                    if(pos[k]>pos[a[j]]) pos[k]=0;
                }
            }
            pos[a[j]]=j;
        }
        for(int j=1;j<=m;j++)
        {
            if(pos[j]!=0) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
//1st csp! rp++