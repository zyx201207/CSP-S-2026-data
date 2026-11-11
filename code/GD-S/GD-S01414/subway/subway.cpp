#include<bits/stdc++.h>
using namespace std;
const int maxn2=10100,maxn=540;
int c,n,d,q;
long long w[maxn2],m,z1[maxn],z[maxn][maxn2];
long long x,xzy,z2[maxn][maxn2],sum=0,ans=1000100000,eer=-1;
int zao(long long x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=z1[i];j++){
			if(x==z[i][j]){
				return i;
			}
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&z1[i]);
		for(int j=1;j<=z1[i];j++){
			scanf("%lld%lld",&z[i][j],&z2[i][j]);
			ans=min(z2[i][j],ans),eer=max(z2[i][j],eer);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&xzy);
		int x1=zao(x),xy1=zao(xzy);
		if(x1==xy1){
			sum=sum+w[x]+w[xzy];
			sum=sum+z2[x1][x]+z2[xy1][xzy];
			printf("%lld\n",sum);
			sum=0;
		}else{
			sum=sum+w[x]+w[xzy]+z2[x1][x]+z2[xy1][xzy];
			cout<<sum+eer<<endl;
			sum=0;
			
		}
	}
	return 0;
}
