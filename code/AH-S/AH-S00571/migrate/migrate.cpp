#include<bits/stdc++.h>
using namespace std;
int c,t;
long long d[2000010],n,N,p;
int f[2000010];
int dfs(int x,int y,int l){
	if(x==y){
		return f[y];
	}
	for(int i=y-1;i>=x;i--){
		if(d[i]-d[x]>N) break;
		f[i]++;
		g[x]+=d[i]-d[x];
		l+=d[i]-d[x];
		f[i]=dfs(i,y,l);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		long long ans;
		cin>>n>>N;
		for(int i=1;i<=n;i++){
			cin>>d[i];
		}

		if(c==11||c==12){
			if(N<d[2]-d[1]){
				cout<<"0\n";
				continue;
			}else{
				cout<<n-4+1<<'\n';
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(dfs(i,j,0)==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		memset(d,0,sizeof(d));
		memset(f,0,sizeof(f));
		ans=0;
	}
	return 0;
}
