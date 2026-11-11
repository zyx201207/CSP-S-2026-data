#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long x[N+1];
int n;
long long d;
int minn;
int zs;
int sear(int u,int v,int wz){
	if(u==v){
		if(minn==-1||wz<minn){
			minn=wz;
			zs=1;
		}
		else if(minn==wz){
			zs++;
		}
		return 0;
	}
	int i=u+1;
	while(i<=v){
		if((x[i]-x[u])<=d){
			sear(i,v,wz+1);
		}
		else{
			break;
		}
		i++;
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	scanf("%d%d",&c,&t);
	for(int i=0;i<t;i++){
		int ans=0;
		int n;
		scanf("%d",&n);
		scanf("%lld",&d);
		for(int j=1;j<=n;j++){
			scanf("%lld",&x[j]);
		}
		for(int j=1;j<=n;j++){
			for(int z=j+3;z<=n;z++){
				minn=-1;
				zs=0;
				sear(j,z,0);
				if(zs==2){
					ans++;
				}
			}
		}
		printf("%d",ans);
		printf("\n");
	}
	return 0;
}
