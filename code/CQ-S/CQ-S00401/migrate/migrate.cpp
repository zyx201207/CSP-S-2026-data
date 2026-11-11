#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
int c, t;
int n;
long long d;
long long x[N];
int mm;
int minmin(int i, int j){
	int num=0;
	for(int l=i,r=i+1;r<=j;r++){
		num++;
		long long a=0;
		while(r<=j){
			if(x[r]-x[r-1]>d) return -1;
			if(a+(x[r]-x[r-1])<=d){
				a+=x[r]-x[r-1];
				r++;
			}
			else break;
		}
		l=r;
	}
	return num;
}
void lu(int m, int i, int j){
	if(m==0){
		if(x[j]-x[i]<=d) mm++;
		return ;
	}
	if(i==j){
		if(m!=0) return ;
	}
	for(int q=i+1;q<=j;q++){
		if(x[q]-x[i]<=d) lu(m-1,q,j);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i+1==j) continue;
				if(x[j]-x[i]<=d) continue;
				//(i,j)
				//求最少次数 
				int m=minmin(i,j);
				if(m==-1) break;
				//求路径数量
				mm=0;
				lu(m,i,j);
				if(mm==2) ans++;;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
