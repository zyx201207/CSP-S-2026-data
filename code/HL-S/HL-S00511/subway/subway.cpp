#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,in=LONG_MAX;
long long w[555555],a[512][55555],k[555555],t[512][55555],v[555555];
vector<long long>fd[555555];
void r(long long f,long long e,long long s){
	if(f==e){in=min(in,s);return ;}
	for(int i=0;i<fd[f].size();i++){
		if(v[i]==1){continue;}
		v[i]=1;
		for(int j=f;j<=k[i];j++){r(a[i][j],e,s+t[i][j]+t[i][a[i][j]]);}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){cin>>w[i];}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			fd[a[i][j]].push_back(i);
		}
	}
	for(long long i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		r(x,y,0);
		cout<<in+w[x]+w[y]<<endl;
		in=LONG_MAX;
	}
	
	return 0;
}