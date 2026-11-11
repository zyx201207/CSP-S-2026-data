#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card1.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500005];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int t[500005];
    int w[500005];
    int c[500005];
    for(int i=1;i<=m;i++)
    {
        memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++)
        {
            t[a[j]]++;
            if(t[a[j]]>1)
            {
                for(int i=w[a[i]];i<j;i++)
                    t[a[i]]--;
            }
            w[a[j]]=j;
        }
        for(int i=1;i<=m;i++)
            c[i]+=t[i];
    }
    for(int i=1;i<=m;i++)
        cout<<c[i]<<" ";
    return 0;
}
