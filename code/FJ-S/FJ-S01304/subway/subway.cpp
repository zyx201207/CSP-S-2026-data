#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long w[N+1];
struct note{
	int bh;
	long long jl;
};
vector<note> xl[505];
long long dis[N+1];
bool vis[N+1];
vector<int> wz[N+1];
int n,m;
note an[N+1];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int j1;
		scanf("%d",&j1);
		for(int j=0;j<j1;j++){
			note x;
	    	scanf("%d",&x.bh);
		    scanf("%lld",&x.jl);
    		xl[i].push_back(x);	
			wz[x.bh].push_back(j1);	
		}
	}
	for(int i=0;i<q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		//solve(u,v);
		//int j1=0;
		/*for(int j=0;j<wz[u].size();j++){
		}*/
		int j1=0;
		long long aaa=-1;
		for(int j=1;j<=n;j++){
			if(xl[j][0].bh==u){
				an[j1].bh=xl[j][1].bh;
				an[j1].jl=xl[j][1].jl;
				long long aa=-1;
				for(int z=0;z<wz[an[j1].bh].size();z++){
					if(xl[wz[an[j1].bh][z]][0].bh==v){
						an[j1].jl+=xl[wz[an[j1].bh][z]][0].bh;
						if(aa==-1||an[j1].jl<=aa){
							aa=an[j1].jl;
						}
					}
					else if(xl[wz[an[j1].bh][z]][1].bh==v){
						an[j1].jl+=xl[wz[an[j1].bh][z]][1].bh;
						if(aa==-1||an[j1].jl<=aa){
							aa=an[j1].jl;
						}
					}					
				}
				if(aaa==-1||aa<=aaa){
					aaa=aa;
				}
				j1++;
			}
		}
		aaa+=w[u];
		aaa+=w[v];
		printf("%lld",aaa);
		printf("\n");
	}
	return 0;
}
