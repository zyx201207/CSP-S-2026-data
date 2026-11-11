#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long a[N];
int n;
long long d;
void dfs(int u,int v,int &cnt,int &res,int &ans){
    if(u==v){
        if(cnt<res){
            ans=1;
            res=cnt;
        }else if(cnt==res){
            ans++;
        }
        return;
    }
    for(int i=u+1;i<=n;i++){
        if(abs(a[u]-a[i])<=d){
            cnt++;
            dfs(i,v,cnt,res,ans);
            cnt--;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long p=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int cnt=0,res=1e9,ans=0;
                dfs(i,j,cnt,res,ans);
                if(ans==2){
                    p++;
                }
            }
        }
        cout<<p<<endl;
    }
    return 0;
}
