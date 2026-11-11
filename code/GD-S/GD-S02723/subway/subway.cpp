#include<bits/stdc++.h>
using namespace std;
long long w[501],m,c,n,d,q,k,o,x,y,T=0,oo=0;
int t[501][203];
vector<long long>a[203],p[502];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=0;i<m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&k);
		for(int j=0;j<k;j++){
			scanf("%lld",&o);
			scanf("%lld",&t[--o][i]);
			a[i].push_back(o);
			p[o].push_back(i);
		}
	}
	for(int i=0;i<q;i++){
		scanf("%lld%lld",&x,&y);
		T=w[--x]+w[--y];
		for(int j=0;j<p[x].size();j++){
			for(int o=0;o<a[p[x][j]].size();o++){
				if(a[p[x][j]][o]==y){
					T+=t[y][p[x][j]];
					T+=t[x][p[x][j]];
				}
			}
		}
		printf("%lld\n",T);
	}
}
