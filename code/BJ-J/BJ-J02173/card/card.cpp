#include<bits/stdc++.h>
const int N=5e5+5;
int a[N],ans[N];
using namespace std;
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
    for(int i=1;i<=n;i++)
    {
        map<int,int> m,pos;
        int cnt=0;
        int c[N];
        for(int j=i;j<=n;j++)
        {
            if(m[a[j]]==0)
            {
                pos[a[j]]=++cnt;
                c[cnt]=pos[a[j]];
                m[a[j]]++;
            }
            else
            {
                for(int k=pos[a[j]];k<=n;k++)
                {
                    c[k]=0;
                    cnt=0;
                }
                pos[a[j]]=++cnt;
                c[cnt]=pos[a[j]];
                m[a[j]]++;
            }
        }
        for(int i=1;i<=cnt;i++)
        {
            if(c[i]==i) ans[j]++;
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }
    return 0;
}