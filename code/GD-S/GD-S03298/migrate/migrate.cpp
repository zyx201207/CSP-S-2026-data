#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
int n,d;
int a[N];
int ans=0;
int cnt=0;
int nd;
void dfs(int nw,int ed,int st){
	if(cnt>2){
		return;
	}
	if(nw==ed){
		if(st==nd){
			cnt++;
		}
		return;
	}
	for(int i=nw+1;i<=ed;i++){
		if(a[i]-a[nw]<=d){
			dfs(i,ed,st+1);
		}
	}
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int nw=i;
			nd=0;
			bool nb=true;
			while(nw<j){
				int res=nw;
				bool fl=false;
				for(int k=nw+1;k<=j;k++){
					if(a[k]-a[nw]>d){
						nw=k-1;
						fl=true;
						break;
					}
				}
				if(!fl){
					nw=j;
				}
				if(nw==res){
					nb=false;
					break;
				}
				nd++;
			}
			if(!nd){
				continue;
			}
			cnt=0;
			dfs(i,j,0);
			if(cnt==2){
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			//cerr<<1;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			if(d==1){
				cout<<0<<'\n';
				continue;
			}
			if(n==1){
				cout<<0<<'\n';
				continue;
			}
			int cd=d/(a[2]-a[1]);
			cd=cd*2-1;
			cerr<<cd<<'\n';
			if(cd<=2){
				cout<<0<<'\n';
				continue;
			}
			cout<<max(0ll,n-cd)<<'\n';
		}
		return 0;
	}
	while(t--){
		solve();
	}
	return 0;
}
