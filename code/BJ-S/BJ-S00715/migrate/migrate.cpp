#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,d;
int a[N];
vector<int> b;
int sum,A;
void dfs(int x,int f,int k){
    if(x==f){
        if(k<A){
            A=k;
            sum=1;
        }else{
            if(k==A){
                sum++;
            }
        }
    }else{

        for(int i=x+1;i<=f;i++){
            if(a[x]+d<a[i]){
                return ;
            }
            if(k<=A){
                dfs(i,f,k+1);
            }
        }
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int bbmq=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            //b.clear();
            sum=0;
            A=1e9;
            dfs(i,j,0);
            if(sum==2){
                bbmq++;
            }
        }
    }
    cout<<bbmq<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
