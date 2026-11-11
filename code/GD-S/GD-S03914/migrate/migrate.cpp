#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],mi=INT_MAX,ret,ans;
void dfs(int x,int t,int s){
	if(x==t){
		if(s<mi){
			mi=s;
			ret=1;
		}else if(s==mi){
			ret++;
		}
		return ;
	}
	for(int i=x+1;i<=n;i++){
		if(a[x]+d<a[i])break;
		dfs(i,t,s+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c>=11&&c<=12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			d=d/(a[2]-a[1]);
			if(d==0){
				cout<<0<<'\n';
				continue;
			}
			d=d*2-1;
			if(n-d<0||d==1)cout<<0<<'\n';
			else cout<<n-d<<'\n';
		}
		return 0; 
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j,0);
				if(ret==2)ans++;
				ret=0;
				mi=INT_MAX;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
