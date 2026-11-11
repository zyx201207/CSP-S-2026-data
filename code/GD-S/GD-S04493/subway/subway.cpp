#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,D,p;
ll my[500005],k[505],a[505][25],t[505][25];
char b[501][500001];
ll d[505][505];
void init(){
	for(ll i=1;i<n;i++){
		for(ll j=2;j<=n;j++){
			ll jg=LLONG_MAX;
			for(ll kk=1;kk<=k[i];kk++){
				if(b[j][a[i][kk]]){
					jg=min(jg,t[j][b[j][a[i][kk]]]+t[i][kk]);
				}
			}
			if(jg<LLONG_MAX){
				d[i][j]=d[j][i]=jg;
			}
		}
	}
}
void floyd(){
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f3f,sizeof(d));
	cin>>c>>n>>m>>D>>p;
	for(ll i=1;i<=m;i++){
		cin>>my[i];
	}
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			b[i][a[i][j]]=j;
		}
	}

	init();
	floyd();	
	for(ll i=1;i<=n;i++){
		d[i][i]=0; 
	}
	 for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	while(p--){
		ll x,y;
		cin>>x>>y;
		vector<ll>v,z;
		for(ll i=1;i<=n;i++){
			if(b[i][x])v.push_back(i);
			if(b[i][y])z.push_back(i);
		}
		ll ans=LLONG_MAX;
		for(ll i=0;i<v.size();i++){
			for(ll j=0;j<z.size();j++){
				ans=min(ans,my[x]+my[y]+t[v[i]][b[v[i]][x]]+t[z[j]][b[z[j]][y]]+d[v[i]][z[j]]);
		//	cout<<ans<<v[i]<<z[j]<<endl;
			}
			
		}
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/


