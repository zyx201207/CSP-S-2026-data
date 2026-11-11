#include<iostream>

using namespace std;

long long w[10010];
long long c,n,m,d,q;
struct st{
	long long a,t;
}cc[10010][1010];
long long k[10010];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q; 
	for(long long i=1;i<=m;i++){
		cin >>w[i];//Õ¾¿Úµ½Õ¾Ìü 
	}
	for(long long i=1;i<=n;i++){
		cin >>k[i];
		for(long long j=1;j<=k[i];j++){
			cin >>cc[i][j].a>>cc[i][j].t;	
		}	
	}
	while(q--){
		long long x,y,ans=0;
		cin >>x>>y;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=k[i];j++){
				if(cc[i][j].a==x||cc[i][j].a==y){
					ans+=cc[i][j].t;
				}	
			}	
		}
		ans+=(w[x]+w[y]);
		cout<<ans<<endl;
	}
	return 0;
} 
