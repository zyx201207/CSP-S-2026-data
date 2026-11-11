#include<bits/stdc++.h>
using namespace std;
const int N=20000005;
int c,t,n;
long long d,p[N];
long long res=0;
int calc(int i,int j)
{
    int ans=0,k=i;
    while(k!=j)
        ans++,k=upper_bound(p+i,p+j+1,p[k]+d)-p-1;
    return ans;
}
void dfs(int k,int i,int j,int need,int now)
{
    if(k>need)
    {
        if(now==j)  res++;
        return;
    }
    for(int q=now+1;q<=n;q++)
    {
        if(p[q]-p[now]>d)   break;
        dfs(k+1,i,j,need,q);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>p[i];
        for(int i=1;i<n;i++)
            if(p[i+1]-p[i]>d)
            {
                n=i;
                break;
            }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++) 
            {
                res=0;
                int need=calc(i,j);
                dfs(1,i,j,need,i);
                if(res==2)   ans++;
            }
        cout<<ans<<'\n';
    }
    return 0;
}