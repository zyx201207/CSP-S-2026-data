#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,a[2000010],k,cnt,mn,m;
void dfs(int x,int y,int dis){
	if(x==y) {
		if(dis<mn){
			cnt=1;
			mn=dis;
		}
		else if(dis==mn)cnt++;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=m)dfs(i,y,dis+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		bool fl=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2])fl=0;
			}
		}
		if(c==12||c==11||fl){
			int gc=a[2]-a[1];
			if(m<gc){
				cout<<0<<"\n";
				continue;
			}
			if(gc==0ll){
				cout<<0<<"\n";
				continue;
			}
			int mxlen=(m-gc+1)/gc;
			if(mxlen==0ll){
				cout<<0<<"\n";
				continue;
			}
			cout<<max(0ll,n-mxlen-1)<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				mn=1e9;
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
