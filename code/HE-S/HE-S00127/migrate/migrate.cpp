#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+7;
int c,T;
int n,d;
int a[N];
bool f[N];
int cnt=0,mi=LLONG_MAX,cnt1=0;
void dfs(int x,int y,int sum,int res){
	if(sum<mi&&x==y){
		mi=sum;
		cnt=1;
		cnt1=res;
		return;
	}else if(sum==mi&&x==y&&res<cnt1){
		cnt1=res;
		cnt=1;
		return;
	}else if(sum==mi&&x==y&&res==cnt1){
		cnt++;
		return;
	}
//	if(sum>mi) return;
//	if(res>cnt1&&cnt1!=0) return;
	//cout<<x<<endl;
	for(int i=x+1;i<=n;i++){
		if(!f[i]&&abs(a[i]-a[x])<=d){
			if(i!=y) f[i]=1;
			dfs(i,y,sum+abs(a[i]-a[x]),res+1);
			f[i]=0;
		}
	}
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=0;
			mi=LLONG_MAX;
			memset(f,0,sizeof f);
			f[i]=1;
			cnt1=0;
			dfs(i,j,0,0);
			if(cnt==2){
				ans++;
				//cout<<i<<" "<<j<<endl;
			} 
			//cout<<endl;
		}
	}
	cout<<ans<<endl;
}
int32_t main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
