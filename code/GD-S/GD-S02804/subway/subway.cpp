#include<bits/stdc++.h>
using namespace std;
long long n,m,q[6010],o,z,mi,a11,d,k[3010],w[1010][1010],e[1010][1010],p,ma[1010];
long long findd(long long x,long long k1){
	for(int i=1;i<=k[k1];i++){
		if(w[k1][i]==x){
			return e[k1][i];
		}
	}
	return 0;
}
long long dfs(long long x,long long y,long long ans){
	ma[x]=1;
	if(x==y){
		mi=min(mi,ans+q[y]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long a=findd(x,i);
		if(a){
			for(int j=1;j<=k[i];j++){
				if(w[i][j]!=x&&!ma[w[i][j]]){
					dfs(w[i][j],y,ans+a+e[i][j]);
				}
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>a11>>n>>m>>d>>z;
	for(int i=1;i<=m;i++){
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>w[i][j]>>e[i][j];
		}
	}
	for(int z1=1;z1<=z;z1++){
		cin>>o>>p;
		mi=99999999;
		memset(ma,0,sizeof(ma));
		dfs(o,p,q[o]);
		cout<<mi<<"\n";
	}
	
	
	return 0;
} 
