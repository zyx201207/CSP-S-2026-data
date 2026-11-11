#include<bits/stdc++.h>
using namespace std;
int mig,t,n;
vector<long long>g[2000010];
long long d,c[2000010];
bool uker(){
	int k=c[2]-c[1];
	for(int i=3;i<=n;i++)if(c[i]-k!=c[i-1])return false;
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&mig,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&c[i]);
		}
		if(d==1)printf("0\n");
		else if(uker()==true){//A
			if(c[2]-c[1]>=d)printf("0\n");
			printf("%lld\n",n-d*2+1);
		}
		else{
			for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)g[i][j]=c[j]-c[i];
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++){
					for(int j=i;j<=n;j++){
						if(g[i][k]<=d&&g[k][j]<=d)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
					}
				}
			}
			printf("%lld\n",g[1][n]);
		}
	}
	return 0;
}
