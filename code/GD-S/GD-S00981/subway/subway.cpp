#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f[500005],g[505],m,n,p[505][505][505],o[505][505],qa,qb,qc,r=LLONG_MAX/3;
vector<pair<long long,long long> >h[505000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);
	for(int i=1;i<=c;i++){
		scanf("%lld",&f[i]);
	}
	for(int i=1;i<=b;i++){
		scanf("%lld",&g[i]);
		for(int j=1;j<=g[i];j++){
			scanf("%lld %lld",&m,&n);
			h[m].push_back({i,n});
		}
	}
	for(int k=0;k<=b;k++){
		for(int i=1;i<=b;i++){
			for(int j=i+1;j<=b;j++){
				p[i][j][k]=r;
			}
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=0;j<h[i].size();j++){
			for(int k=j+1;k<h[i].size();k++){
				long long x,y;
				if(h[i][j].first>h[i][k].first){
					x=h[i][j].first;
					y=h[i][k].first;
				}
				else{
					x=h[i][k].first;
					y=h[i][j].first;
				}
				p[y][x][0]=min(p[y][x][0],h[i][j].second+h[i][k].second);
			}
		}
	}
	for(int i=1;i<=b;i++){
		for(int j=1;j<=b;j++){
			for(int k=j+1;k<=b;k++){
				long long x=0;
				if(j>i){
					x+=p[i][j][i-1];
				}
				else{
					x+=p[j][i][i-1];
				}
				if(k>i){
					x+=p[i][k][i-1];
				}
				else{
					x+=p[k][i][i-1];
				}
				p[j][k][i]=min(p[j][k][i-1],x);
			}
		}
	}
	for(int i=1;i<=e;i++){
		scanf("%lld %lld",&qa,&qb);
		qc=r;
		for(int j=0;j<h[qa].size();j++){
			for(int k=0;k<h[qb].size();k++){
				int x,y;
				if(h[qa][j].first>h[qb][k].first){
					x=h[qb][k].first;
					y=h[qa][j].first;
				}
				else{
					y=h[qb][k].first;
					x=h[qa][j].first;
				}
				qc=min(qc,h[qa][j].second+h[qb][k].second+p[x][y][b]);
			}
		}
		printf("%lld\n",qc+f[qa]+f[qb]);
	}
	return 0;
}
