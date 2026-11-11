#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
bool f[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    memset(f,1,sizeof(f));
    for(int mk=30;mk>=0;mk--)
    {
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(!f[i]) continue;
            if(a[i]&(1<<mk)) c++;
        }
        if(c<m) continue;
        ans|=(1<<mk);
        for(int i=1;i<=n;i++)
        {
            if(!f[i]) continue;
            if(!(a[i]&(1<<mk))) f[i]=false;
        }
    }
    cout<<ans;
    return 0;
}
