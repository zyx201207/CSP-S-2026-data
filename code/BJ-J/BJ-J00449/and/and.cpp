#include<bits/stdc++.h>
using namespace std;
int l(int i)
{
    return i&(i-1);
}
struct q
{
    int nu,g;
}s[200010];
bool cmp(q a,q b){
    return a.nu>b.nu;
}
int n,m;
int ans=0;
int vis[200010];
int a[200010]={};
int in(int m,int i){
    if(m<1)return a[i];
    for(int i=1;i<=n;i++){
        if(vis[i]==1)continue;
        vis[a[i]]=1;
        ans=in(m-1,i)&a[i];
        vis[a[i]]=0;
    }
    return ans;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(pow(n,m)<=10000010){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            vis[a[i]]=1;
            ans=max(ans,a[i]&in(m-1,i));
            vis[a[i]]=0;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>s[i].nu;
        int x=s[i].nu;
        while(x>0){
            x=l(x);
            s[i].g++;
        }
    }
    sort(s+1,s+n+1,cmp);
    int ans2=s[1].nu;
    for(int i=1;i<=m;i++){
        ans2&=s[i].nu;
    }
    cout<<ans2;
    return 0;
}
