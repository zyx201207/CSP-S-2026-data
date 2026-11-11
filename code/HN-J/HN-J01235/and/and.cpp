#include<iostream>
int a[32][200001],ans[32];
bool can[200001];
int n,m;
int b;
void z(int i,int b){
	int j=31;
	while(b){
		a[j][i]=b%2;
		b/=2;
		--j;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&b);
		z(i,b);
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=31;++j) printf("%d",a[j][i]);
//		printf("\n");
//	}
	for(int i=1;i<=31;++i){
		int x=0;
		for(int j=1;j<=n;++j)
			if(!can[j])
				if(a[i][j]) ++x;
//		printf("%d\n",x);
		if(x>=m){
			ans[i]=1;
			for(int j=1;j<=n;++j)
				if(!a[i][j]) can[j]=1;
//			for(int j=1;j<=n;++j)
//				printf(" %d ",int(can[j]));
		}
	}
	int sum=0,c2=1;
	for(int i=31;i>=0;--i){
		sum+=(c2*ans[i]);
		c2*=2;
	}
	printf("%d",sum);
	return 0;
}
