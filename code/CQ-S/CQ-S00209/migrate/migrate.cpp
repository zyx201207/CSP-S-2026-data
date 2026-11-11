#include<iostream>
using namespace std;
int cid,t;
void solve();
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cid,&t);
	while(t--)solve();
	return 0;
}
int n;
long long d,a[2000006];
int ld[2000006],rd[2000006];
int lx[2000006],rx[2000006];
int cl[2000006],cr[2000006];
void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		lx[i]=rx[i]=1;
		cl[i]=cr[i]=0;
	}
	int lxx=1;
	for(int i=1;i<=n;i++){
		while(a[lxx]<a[i]-d)lxx++;
		ld[i]=lxx;
	}
	lxx=n;
	for(int i=n;i;i--){
		while(a[i]<a[lxx]-d)lxx--;
		rd[i]=lxx;
	}
	for(int i=1;i<=n;i++){
		if(rd[i]>i+1&&i>=ld[rd[i]]){
			cl[rd[i]]++;
		}
		if(ld[i]<i-1&&i<=rd[ld[i]]){
			cr[ld[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(rd[i]==i)continue;
		if(ld[rd[i]]==i){
			lx[rd[i]]+=lx[i];
		}else lx[rd[i]]++;
	}
	for(int i=n;i;i--){
		if(ld[i]==i)continue;
		if(rd[ld[i]]==i){
			rx[ld[i]]+=rx[i];
		}else rx[ld[i]]++;
	}
	for(int i=1;i<=n;i++)lx[i]--,rx[i]--;
	long long res=0;
	int cnt=0;
	for(int i=2;i<n-1;i++){
		if(a[i+1]-a[i]>d)continue;
		if(ld[i+1]==i||rd[i+1]==i)continue;
		res+=(long long)cl[i+1]*cr[i];
		if(ld[rd[i]]==i&&rd[i]==rd[i+1]){
			res+=(long long)cl[i+1]*rx[rd[i]];
		}
		if(rd[ld[i]]==i+1&&ld[i]==ld[i+1]){
			res+=(long long)cr[i]*lx[ld[i]];
		}
		if(rd[ld[i+1]]==i+1&&ld[rd[i]]==i&&ld[i]==ld[i+1]&&rd[i]==rd[i+1]){
			res+=(long long)lx[ld[i]]*rx[rd[i]];
		}
	}
	printf("%lld\n",res);
	return ;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/ 
