#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,T;ll d;
ll x[N];
int cnt,ans=1e9,z;
void dfs(int u,int des,int k){
    if(k>ans) return;
    if(u==des){
        
        if(ans>k){
            ans=k;
            cnt=0;
        }     
        if(ans==k) cnt++;   
        return;
    }
    for(int i=u+1;i<=des;++i){
        if(x[i]-x[u]<=d) dfs(i,des,k+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        int n;
        cin>>n>>d;
        z=0;
        //cout<<d<<'\n';
        for(int i=1;i<=n;++i) cin>>x[i];
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                dfs(i,j,0);
                //cout<<cnt<<' ';
                if(cnt==2) ++z;
                cnt=0;
                ans=1e9;
            }
        }
        cout<<z<<'\n';
    }
    
    return 0;
}