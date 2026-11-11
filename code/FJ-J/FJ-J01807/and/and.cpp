#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
ll st[N][30];
ll ret[N];
int n,m;
ll mx=0;
void dfs(int now,int cnt){
	if(now>n){
		if(cnt==m){
			ll ans=ret[0];
			for(int i=1;i<m;i++){
				ans=(ans&ret[i]);
			}
			mx=max(mx,ans);
		}
		return;
	}
	dfs(now+1,cnt);
	ret[cnt]=a[now];
	dfs(now+1,cnt+1);
}
void solve1(){
	ll ans=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				ans=max(ans,(a[i]&a[j]));
			}
		}	
	}
	cout<<ans;
}
void solve2(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
	}
	for(int j=1;j<=30;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=(st[i][j-1]&st[i+(1<<(j-1))][j-1]);
		}
	}
	int k=log2(n-1);
	ans=max((st[2][k]&st[n-(1<<k)+1][k]),(st[1][k]&st[n-(1<<k)][k]));
	for(int i=2;i<n;i++){
		int kl=log2(i-1);
		int kr=log2(n-i);
		ans=max(ans,(st[1][kl]&st[i-(1<<kl)][kl])&(st[i+1][kr]&st[n-(1<<kr)+1][kr]));
	}
	cout<<ans;
}
int find(ll x){
	int l=1,r=n;
	int best=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]>=x){
			best=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return best;
}
void solve3(){
	ll ans=0;
	sort(a+1,a+n+1);
	int last=n;
	for(int k=30;k>=0;k--){
		int id=find((1<<k));
		if(id==-1){
			continue;
		}
		if(last-id+1>=m){
			ans=a[last];
			for(int i=last-m+1;i<last;i++){
				ans&=a[i];
			}
			break;
		}
		last=id-1;
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1,0);
		cout<<mx;
	}
	else if(n<=2000){
		solve1();
	}
	else if(n==m-1){
		solve2();
	}
	else{
		solve3();
	}
	return 0;
}
