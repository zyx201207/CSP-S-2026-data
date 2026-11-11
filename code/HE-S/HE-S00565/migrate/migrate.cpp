#include <iostream>
#include <cstdio>
#define int long long
#define inf 1e18
using namespace std;
const int max_n=2e6+5;
int n,d,a[max_n],c;
int dp[max_n];
int ans_num,cs;
void dfs(int x,int y,int num){
	if(x==y){
		if(ans_num>num){
			ans_num=num;
			cs=1;
		}else cs++;
	}
	if(c>=15&&c<=18) if(num>10) return;
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]>d) return;
		dfs(i,y,num+1);
	}
}
void slove(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d) break;
			ans_num=inf;
			cs=0;
			dfs(i,j,0);
			if(cs==2) ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;cin>>c>>T;
	while(T--) slove();
	return 0;
}
