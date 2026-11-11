#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll inf = 2e5+7;
ll n,m,i,j,k,l,h,maxn=-1e9;
ll a[inf];
void dfs(ll x,ll ans,ll cnt){
//	cout<<x<<" "<<cnt<<endl;
	if(ans==m){
		maxn=max(maxn,cnt);
		return ;
	}
	if(x>n) return ;
	if(cnt==-1) dfs(x+1,ans+1,a[x]);
	else dfs(x+1,ans+1,cnt&a[x]);
	dfs(x+1,ans,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	sort(a+1,a+1+n);	
	for(i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,-1);
		cout<<maxn;
	}
	else if(m==1){
		for(i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}
	else if(m==2){
		for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) maxn=max(maxn,(a[i]&a[j]));
		cout<<maxn;
	}
	else if(n==m){
		h=a[1];
		for(i=2;i<=n;i++) h=h&a[i];
		cout<<h;
	}
	else if(m==n-1){
		for(i=1;i<=n;i++){
			if(i==1) h=a[2];
			else h=a[1];
			for(j=1;j<=n;j++){
				if(j==i) continue;
				h=h&a[i];
			}
			maxn=max(maxn,h);
		}
		cout<<maxn;
	}
	else{
		cout<<a[m];
	}
	return 0;
}
