#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
ll n,m,s,ans,p[40],a[200010];
ll k=(1ll<<30)-1;
ll pre[200010],suf[200010];
ll popc(ll x){
	ll cnt=0;
	while(x){
		if(x&1) cnt++;
		x>>=1;
	}
	return cnt;
}
ll checkA(){
	rep(i,1,n){
		if(popc(a[i]+1)!=1) return 0;
	}
	return 1;
}
ll checkB(){
	if(popc(n)!=1) return 0;
	rep(i,1,n){
		if(a[i]!=i-1) return 0;
	}
	return 1;
}
void dfs(int u,int cnt,ll w){
	if(cnt>m) return;
	if(u==n+1){
		if(cnt==m) ans=max(ans,w);
		return;
	}
	dfs(u+1,cnt+1,(w&a[u]));
	dfs(u+1,cnt,w);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	rep(i,1,n){
		cin >> a[i];
	}
	if(n<=20){
		dfs(1,0,k);
		cout << ans;
		return 0;
	}else if(m==1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}else if(m==n){
		rep(i,1,n) s=(s&a[i]);
		cout << s;
		return 0;
	}else if(m==n-1){
		pre[0]=suf[n+1]=k;
		rep(i,1,n) pre[i]=(pre[i-1]&a[i]);
		per(i,n,1) suf[i]=(suf[i+1]&a[i]);
		rep(i,2,n-1) ans=max(ans,(pre[i-1]&suf[i+1]));
		ans=max(ans,max(pre[n-1],suf[2]));
		cout << ans;
		return 0;
	}else if(checkA() || checkB()){
		sort(a+1,a+n+1);
		ans=k;
		rep(i,n-m+1,n) ans&=a[i];
		cout << ans;
		return 0;
	}else if(n<=20000 && m==2){
		rep(i,1,n) rep(j,i+1,n) ans=max(ans,(a[i]&a[j]));
		cout << ans;
		return 0;
	}
	rep(i,0,29){
		int cnt=0;
		rep(j,1,n){
			if((a[j]>>i)&1) cnt++;
		}
		if(cnt<m){
			rep(j,1,n){
				if((a[j]>>i)&1) a[j]-=(1ll<<i);
			}
		}
	}
	rep(i,1,n){
		a[i]^=k;
	}
	sort(a+1,a+n+1);
	rep(i,0,29) p[i]=1;
	rep(i,1,m){
		rep(j,0,29){
			if(((a[i]>>j)&1)==1) p[j]=0;
		}
	}
	per(i,29,0) ans=ans*2+p[i];
	cout << ans;
	return 0;
}
