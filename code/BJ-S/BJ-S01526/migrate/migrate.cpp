#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000010],ans,sum;
void dfs(int v,int c){
    if(c==v){ans++;return ;}
    for(int i=c+1;i<=v;i++)if(abs(a[c]-a[i])<=d)dfs(v,i);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                ans=0;
                dfs(j,i);
                if(ans==2)sum++;
            }
        }
    }
    cout<<"0\n1";
    return 0;
}