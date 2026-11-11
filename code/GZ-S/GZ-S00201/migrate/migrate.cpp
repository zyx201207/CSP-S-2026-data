//观山湖中学 李朋钊 GZ-S00201
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
template<typename U, typename V> bool cmin(U &x,const V &y){return y<x?x=y,1:0;}
template<typename U, typename V> bool cmax(U &x,const V &y){return y>x?x=y,1:0;}
ll n, d, x[N], res, minx=Inf;
void dfs(int i,int r,ll sum){
    if(i>=r){
        if(cmin(minx,sum)) res=1;
        else if(minx==sum) res++;
        return ;
    }
    for(int xx=i+1;xx<=r;xx++){
        if(x[xx]-x[i]<=d){
            dfs(xx,r,sum+1);
        }
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            res=0;
            minx=Inf;
            dfs(i,j, 0);
            cnt+=(res==2);
        }
    }
    cout<<cnt<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T,C;cin>>C>>T;
	while(T--){
        solve();
	}
	return 0;
}
