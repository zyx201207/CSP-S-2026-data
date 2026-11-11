#include<iostream>
#include<algorithm>
#include<vector>
int c,t,n,cnt,ans;
long long x[2000100],d;
void reset(){
	ans=0;
}
void init(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
}
void find(int lst,int v,int tm){
	if(tm==1){
		if(x[v]-x[lst]<=d) cnt++;
		return;
	}
	for(int i=lst+1;i<=v-tm+1;i++){
		if(x[i]-x[lst]>d) break;
		find(i,v,tm-1);
	}
}
void process(){
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++){
			cnt=0;
			for(int k=1;cnt==0&&k<=j-i;k++) find(i,j,k);
			if(cnt==2) ans++;
		}
}
void print(){
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		reset();
		init();
		process();
		print();
	}
	return 0;
}
