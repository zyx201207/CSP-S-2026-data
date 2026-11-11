#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e6+5;
int n,pre[N],suf[N];
ll d,ans,a[N],dis[5005][5005];
void work(){
	ans=0;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n>5000){
		printf("0\n");
		return;
	}
	int tot=1;
	for(int i=1;i<=n;i++){
		while(tot<n&&a[tot+1]-a[i]<=d) tot++;
		suf[i]=tot;
	}
	tot=n;
	for(int i=n;i>=1;i--){
		while(tot>1&&a[i]-a[tot-1]<=d) tot--;
		pre[i]=tot;
	}
	for(int i=1;i<=n;i++){
		ll sum=i;
		int now=i;
		for(int j=i+1;j<=n;j++){
			dis[i][j]=sum+j;
			if(suf[now]==j){
                sum+=j;
                now=suf[now];
                if(suf[now]==now) break;
            }
		}
	}
	for(int i=n;i>=1;i--){
		ll sum=i;
		int now=i;
		for(int j=i-1;j>=1;j--){
			if(dis[j][i]-(sum+j)==1) ans++;
			if(pre[now]==j){
                sum+=j;
                now=pre[now];
                if(pre[now]==now) break;
            }
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _c,_;
	scanf("%d%d",&_c,&_);
	while(_--) work();
}
/*
15:30
开始思考
半个小时后两题每题15min
15:50
好像会了 n^3，考虑从前往后和从后往前跳
16:12 好像有 n^2log?决定先实现
16:26 写了n^2
*/