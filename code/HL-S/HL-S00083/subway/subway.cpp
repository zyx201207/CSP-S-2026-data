#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,aa,x,y;
long long wi[500005],tt,fl[505][505];
int ki[505];
vector<int> a[505],da[500005];
vector<long long> t[505],dt[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		scanf("%lld",&wi[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			fl[i][j]=1e18;
		}
	}
	for (int i=1;i<=n;i++){
		cin>>ki[i];
		for (int j=0;j<ki[i];j++){
			scanf("%d%lld",&aa,&tt);
			for (int k=0;k<da[aa].size();k++){
				if (fl[da[aa][k]][i]>dt[aa][k]+tt){
					fl[da[aa][k]][i]=fl[i][da[aa][k]]=dt[aa][k]+tt;
				}
			}
			a[i].push_back(aa);
			t[i].push_back(tt);
			da[aa].push_back(i);
			dt[aa].push_back(tt);
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (fl[i][j]>fl[i][k]+fl[k][j]){
					fl[i][j]=fl[i][k]+fl[k][j];
				}
			}
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		long long as=1e18;
		for (int i=0;i<da[x].size();i++){
			for (int j=0;j<da[y].size();j++){
				as=min(as,dt[x][i]+dt[y][j]+fl[da[x][i]][da[y][j]]);
			}
		}
		printf("%lld\n",as+wi[x]+wi[y]);
	}
	return 0;
}
// cant you cant you see me again
// let me 300+ ?