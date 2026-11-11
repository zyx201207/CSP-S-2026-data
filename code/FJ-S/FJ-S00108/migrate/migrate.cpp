#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
const ll INF=1ll<<60;
ll a[N];
ll d;
int n;
struct node{
	int u;
	ll t;
};
ll check(int st,int ed){
	queue<node> q;
	q.push({st,0});
	ll ans=INF,cnt=0;
	while(!q.empty()){
		int u=q.front().u;
		ll t=q.front().t;
		q.pop();
		if(u==ed){
			if(t<ans){
				ans=t;
				cnt=1;
			}else if(t==ans)cnt++;
			continue;
		}
		for(int v=u+1;v<=n;v++){
			if(a[v]-a[u]>d)break;
			q.push({v,t+1});
		}
	}
	return cnt==2;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %lld",&n,&d);
		int flag=1,dd=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i==2)dd=a[i]-a[i-1];
			if(i>2&&a[i]-a[i-1]!=dd)flag=0;
		}
		if(n<=3){
			printf("0\n");
			continue;
		}
		if(flag){
			if(d/dd==2){
				printf("%lld\n",n-d/dd-1);
			}else printf("0\n");
			continue;
		}
		ll ans=0;
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}