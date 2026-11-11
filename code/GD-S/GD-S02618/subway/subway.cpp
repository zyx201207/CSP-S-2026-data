#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x,y,ans=10000000;
long long w[500010];
long long k[2090];
long long a[1090][1090],t[1090][1090],sf[1090];
void f(long long x,long long y,long long zt){//
	if(x==y&&ans>zt){
//		cout<<x<<' '<<zt<<'\n';
		ans=zt;
	}
	long long sfjg[1090],z=1;
	memset(sfjg,0,sizeof(sfjg));
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==x){
				sfjg[z]=i;
//				cout<<x<<' '<<i<<'\n';
				z++;
			}
		}
//		cout<<'\n';
	} 
	for(int l=1;l<=z;l++){
		for(long long i=1;i<=k[sfjg[l]];i++){
			auto it=a[sfjg[l]][i];
			if(sf[it]==0){
				sf[it]=1;
//				cout<<it<<' ';
				f(it,y,zt+t[sfjg[l]][it]+t[sfjg[l]][x]);
			}
		}	
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		ans=10000000;
		memset(sf,0,sizeof(sf));
		sf[x]=1;
		f(x,y,0);
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<'\n';
	}
	return 0;
}
/* 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
