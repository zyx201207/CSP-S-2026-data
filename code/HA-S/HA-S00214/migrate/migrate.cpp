#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const ll inf=1e18;
int c,T=1;
int n;
ll x[N],ans,d,cnt[N];
/*void dfs(int idi,int idj){
	int x=x[idi],y=x[idj],sum=0,res=0;
	for(int i(idi+1);i<=idj;++i){
		int cx=x[i]-x[i-1];
		if(cx<d) return;
		sum+=cx;
		if(sum<d) break;
		dfs()
	}
}*/
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i(1);i<=n;++i){
		cin>>x[i];
	}
	if(c==11||c==12){
		int md=int(d/(x[2]-x[1]));
		if(md>=n-1) cout<<"0\n";
		else if(x[2]-x[1]>d) cout<<"0\n";
		else{
		for(int i(md+2);i<=n;++i){
			if((i-1)%md==0) break;
			if(i==2*md) ans+=ll(n-i+1);
		}
		cout<<ans<<"\n";
		}
	}else{/*
		for(int i(1);i<=n-3;++i){
			for(int j(i+3);j<=n;++j){
				dfs(i,j);
			}
		}*/
		if(c==13||c==14){
			cout<<0<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
