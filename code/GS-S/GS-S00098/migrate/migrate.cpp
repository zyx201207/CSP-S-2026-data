#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long  c,T,n,d;
long long  cc;
long long  a[N];
long long  mx=N;
void dfs(int u,int v,int cs){
    if(u==v){
        // cout<<cs<<" ";
        if(cs==mx){
            cc++;
        }
        if(cs<mx){
            mx=cs;
            cc=1;
        }
    }
    for(int i=u+1;i<=n;i++){
        if(i>v)return;
        if(fabs(a[i]-a[u])<=d){
            // cout<<u<<"->"<<i<<" ";
            dfs(i,v,cs+1);
            // cout<<cc<<" ";
        }
        
        
    }
    // cout<<cc<<" ";
}
int main(){
    freopen("migrate.in","r",stdin);//!!!!!!!!!!
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        int cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        // cout<<a[1];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                // cout<<i<<" "<<j<<" ";
                dfs(i,j,0);
                // cout<<cc;
                if(cc==2)cnt++;
                cc=0;
                mx=N;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}