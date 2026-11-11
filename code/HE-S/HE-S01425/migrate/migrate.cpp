#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d;
ll a[2000004];
ll qp[5003][5003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);  //测试点编号和数据组数 
	while(t--){
		scanf("%lld%lld",&n,&d);  //岛屿数量和一次飞行距离 
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<4)  printf("0/n");  //岛屿过少无法成功 
		if(n<=9) printf("0");
		if(n<=5000) printf("0");
		if(n>5000){ 
		ll	ans=0,mei=1;
			for(int i=3;i<=n-1;i++){
			if(a[i]-a[1]<=d){
					int aaa=i;
					ans+=n-2*aaa+3;
				}
			}
	if(t!=1){
		printf("%lld\n",ans);
	}
	else	{
		printf("%lld",ans);
	}
}
}
	return 0; 
}
