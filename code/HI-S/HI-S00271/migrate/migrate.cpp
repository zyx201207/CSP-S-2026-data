#include <bits/stdc++.h>
using namespace std;
int c, t;
int n;
long long d;
long long a[2000002];
int b[2000002];
int mn;
void fd(int st, int ed, int stp){
	if(st==ed){
		mn=min(mn, stp);
		b[stp]+=1;
		return ;
	} 
	for(int i=st+1;i<=ed;i++){
		if(a[i]-a[st]<=d){
			fd(i, ed, stp+1);
		}else{
			break;
		}
	} 
	return ;
}
void solve(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				b[k]=0;
			}
			mn=j-i;
			if(mn<=d)continue;
			fd(i, j, 0);
			if(b[mn]==2)cnt+=1;
		}
	}
	printf("%d\n", cnt);
	return ;
} 
long long cha;
void solve2(){
	long long numb;
	numb=d/cha;
	if(numb>=n-1||numb==1){
		printf("0\n");
		return ;
	}
	int ans=0;
	for(int i=numb+1;i<=numb*2-1;i++){
		if(i>n-1)break;
		ans=ans+(n-i);
	}
	printf("%d\n", ans);
	return ;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%lld", &n, &d);
		int flg=1;
		for(int i=1;i<=n;i++){
			scanf("%lld", &a[i]);
			if(i==2)cha=a[i]-a[i-1];
			if(i>2){
				if(cha!=a[i]-a[i-1]){
					flg=-1;
				}
			}
		}
		if(flg==1){
			solve2();
			continue;
		}
		solve();
	} 
    return 0;
}
