#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(x) freopen(x".in","r",stdin);
#define fop(x) freopen(x".out","w",stdout);
#define IO(x) fin(x)fop(x)
ll n,m,a[200005],ans;
bool use[200005]={0};
void dfs(int p,int num){
	if(p>n){
		return;
	}
	if(n-p<m-num){
		return;
	}
	if(num==m){
		ll f=-1;
		ll maxx2;
		for(int i=0;i<n;i++){
			if(use[i]){
				if(f==-1){
					maxx2=a[i];
					f=0;
				}
				maxx2=(maxx2&a[i]);
			}
		}
		ans=max(ans,maxx2);
		return;
	}
	use[p]=1;
	dfs(p+1,num+1);
	use[p]=0;
	dfs(p+1,num);
	return;
}
int main(){
	IO("and")
	cin>>n>>m;
	ll maxx=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		ans=a[0];
		for(ll i=1;i<n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
