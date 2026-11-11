#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,INF=0x3f3f3f3f3f3f3f3f;
int n,d;
int a[N];
int res=INF,acnt;
void dfs(int x,int ed,int dep){
	if(x==ed){
		if(res>dep) res=dep,acnt=1;
		else if(res==dep) acnt++;
		return;
	}
	for(int i=x+1;a[i]-a[x]<=d&&i<=ed;i++)
		dfs(i,ed,dep+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T; cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C<=6){
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					res=INF,acnt=0;
					dfs(i,j,0);
					if(acnt==2) ans++;
				}
			cout<<ans<<'\n';
			continue;
		}
		else{
			int m=a[2]-a[1];
			int k=d/m;
			if(k<=1) cout<<0<<'\n';
			else cout<<max((int)0,n-2*k+1)<<'\n';
			continue;
		}
	}
	return 0;
}


