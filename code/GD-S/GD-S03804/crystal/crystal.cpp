#include<bits/stdc++.h>
using namespace std;
using ll=long long;
priority_queue<ll,vector<ll>,greater<ll>> q;
ll n,m,a[5000005],ans,cnt,avg,res;
ll dfs(ll czcs,ll gs,int l,int r){
	if(czcs>m){
		return ans;
	}if(gs==r-1){
		if(czcs>m){
			return ans;
		}if(l==r) return gs+1;
		return gs;
	}for(int i=l;i<r;i++){
		ans=max(ans,dfs(a[r]-a[i]+czcs,gs+1,i+1,r));
	}if(l==r) return ans>gs+1?ans:gs+1;
	return ans>gs?ans:gs;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll ai;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&ai);
		q.push(ai);
		cnt+=ai;
	}ai=1;
	while(!q.empty()){
		a[ai]=q.top();
		q.pop();
		ai++;
	}ai--;
	avg=floor(cnt*1.0/n+0.5);
	for(int i=1;i<=n;i++){
		a[i]-=avg;
	}ll l=0,r=cnt-a[n];
	for(int i=1;i<=n;i++){
		ans=max(ans,dfs(0,0,1,i));
	}printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}






































