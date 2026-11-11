#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
int C,n,d,ans,rflag,num;
int a[N],cnt[N];
void solve();
void dfs(int x,int ed,int cntw,int minw){
	if(rflag) return ;
	if(a[x]>=a[ed]){
		num++;
		if(num>2){
			rflag=1;
		}
		return ;
	}
	int t=upper_bound(a+1,a+n+1,a[x]+d)-a-1;
	t=min(t,ed);
	for(int i=t;i>x;i--){
		if(cntw+1<=minw) dfs(i,ed,cntw+1,minw);
		if(rflag) return ;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			bool flag=0;
			rflag=0;
			num=0;
			int w=a[i],res=0;
			while(w<a[j]){
				int t=upper_bound(a+1,a+n+1,w+d)-a-1;
				if((!(1<=t&&t<=n))||w==a[t]){
					flag=1;
					break;
				}
				res++;
				w=a[t];
			}
			if(flag) continue;
			dfs(i,j,0,res);
			if(num==2) {
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
