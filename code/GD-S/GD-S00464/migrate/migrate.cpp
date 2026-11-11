#include<cstdio>
#include<iostream>
using namespace std;
int c,t;
int n;
long long a[2000005],d;
int dis[5005][5005];
long long tc[5005][5005];
void pfget(){
	int ans=0;
	while(t--){
		//cls-dis
		//cls=tc
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i=i+1)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i=i+1)
			for(int j=1;j<=n;j=j+1)dis[i][j]=0x3f3f3f3f;
		for(int i=1;i<=n;i=i+1)
			for(int j=1;j<=n;j=j+1)tc[i][j]=1;
		//csh
		for(int i=1;i<=n;i=i+1)dis[i][i]=0;
		for(int i=1;i<=n;i=i+1)
			for(int j=i+1;j<=n;j=j+1)
				if(a[j]-a[i]<=d)dis[i][j]=dis[j][i]=1;
		//add-edge
		for(int k=1;k<=n;k=k+1)
			for(int i=1;i<=n;i=i+1)
				for(int j=1;j<=n;j=j+1)
					if(i==j)continue;
					else if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						tc[i][j]=tc[i][k]*tc[k][j];
					//i->k->j
					}
					else if(dis[i][j]==dis[i][k]+dis[k][j]){
						if(i==k||k==j)continue;
						tc[i][j]=tc[i][j]+tc[i][k]*tc[k][j];
					//i->j-or-i->k->j
					}
				//j-end
			//i-start
		//k-mid
		ans=0;
		for(int i=1;i<=n;i=i+1)
			for(int j=i+1;j<=n;j=j+1)ans=ans+((tc[i][j]==2)?1:0);
		printf("%d\n",ans);
	//1group
	}
	return;
//floyd-n*n*n
//pf思路：暴力出奇迹，对于每一组测试数据，建图，跑flo(n*n*n) 
}
void pfmath(){
	long long k,num,ans;
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i=i+1)scanf("%lld",&a[i]);
		//printf("%d,inputok.\n",t);
		if(a[2]==a[1]||(a[2]-a[1])>d){
			printf("0\n");
			continue;
		//same
		}
		k=d/(a[2]-a[1]);
		num=max((long long)n-k-1,(long long)0);
		ans=num*(num-1)/2;
		printf("%lld\n",ans);
	//1group
	}
	return;
//等差数列-wa+tle
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=10)pfget();
	else if(c<=12)pfmath();
	return 0;
//migrate-T3
//测试样例通过情况：001ok. 002ok. 003ok.
//检查情况： 18:15:10.01
}
