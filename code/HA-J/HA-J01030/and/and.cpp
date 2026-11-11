#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],an[200005],ans,en,maxn,t[60];
void dfs(ll nxt,ll sum,ll cnt,bool pd){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=nxt+1;i<=n;i++){
		if(!pd){
			dfs(i,a[i],cnt+1,1);
		}
		else{
			dfs(i,sum&a[i],cnt+1,1);
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==1) an[i]=a[i];
		else an[i]=an[i-1]&a[i];
	}
	if(n<=2000){
		dfs(0,0,0,0);
	}
	else if(m==n-1){
		for(int i=n-1;i>=0;i--){
			if(i==0){
				ans=max(ans,en);
				break;
			}
			ans=max(ans,an[i]&en);
			if(i==n-1) en=a[n];
			else en&=a[i+1];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ll k=log2(a[i]);
			t[k]++;
			if(t[k]>=m)ans=max(ans,a[i]);
		}
	} 
	cout<<ans;
	return 0;
} 
