#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int g[N];
int ans=INT_MAX,mx;
bool cmp(int a,int b){
return a>b;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>g[i];
        mx=max(mx,g[i]);
    }

    if(m==1){
        cout<<mx;
        return 0;
    }else if(m==2){
        int ans=0;
        sort(g+1,g+n+1);
        for(int i=1; i<n; i++)
            for(int j=i; j<=n; j++)
                ans=max(ans,g[i]&g[j]);
        cout<<ans;
        return 0;
    }else if(m==n){
        int ans=INT_MAX;
        for(int i=1; i<=n; i++)
            ans&=g[i];
        cout<<ans;
    }

    sort(g+1,g+n+1,cmp);
    for(int i=1; i<=m; i++)
        ans&=g[i];

    cout<<ans;
    return 0;
}
