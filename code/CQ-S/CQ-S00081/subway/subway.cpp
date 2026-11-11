#include<bits/stdc++.h>
using namespace std;
int c;
long long n,m,d,q,w[500001],k[501],a[501][500001],t[501][500001],xis[500001],maxki,kk[500001];
vector<long long> v[500001];
queue<long long> qq;
void solve(long long x,long long y){
	qq.push(x);
	xis[x]=1;
	kk[x]=w[x];
	while(!qq.empty()){
		long long nm=qq.front();
		for(auto i:v[nm]){
			if(xis[i]==0){
				qq.push(i);
				for(int i=1;i<=n;i++){
					
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		maxki=max(maxki,k[i]);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j>=2){
				v[a[i][j]].push_back(a[i][j-1]);
				v[a[i][j-1]].push_back(a[i][j]);
			}
		}
	} 
	while(q--){
		long long x,y;
		cin>>x>>y;
		if(x==y)cout<<0;
		if(maxki==2)solve(x,y);
	}
	return 0; 
} 
