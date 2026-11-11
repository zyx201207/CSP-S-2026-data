#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ri=2e6+5;
ll ans,cnt,c,t,n,d,x[ri],fk,f[ri];
void dfs(int u,int v,int res){
	if(u==v){
		if(res<ans){
			cnt=1;
			ans=res;
		} else{
			cnt++;
		}
		return;
	}
	if(res>ans) return;
	for(int i=u+1;i<=v;i++){
		if(x[i]-x[u]<=d) dfs(i,v,res+1);
		else break;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(11<=c&&c<=12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			fk=0;
			for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
			ll gc=x[2]-x[1];
			ll L=d/gc;
			if(L<=1){puts("0");continue;}
			ll nc=L+L-1;
			printf("%lld\n",max(0ll,n-nc)); 
		}
		return 0;
	}
	while(t--){
		scanf("%lld%lld",&n,&d);
		fk=0;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			    cnt=0,ans=0x3f3f3f3f;
				dfs(i,j,0);
				if(cnt==2) fk++;
			}
		}
		printf("%lld\n",fk);
	}
	return 0;
} 
/*
20分，我怎么这么没用 
*/
