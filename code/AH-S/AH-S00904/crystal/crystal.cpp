#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[100100],cnt=0,ans=0;
void dfs(ll t,ll he,ll h){
	if(he>m||t>=n){
		if(h>ans) ans=h;
		return;
	}
	dfs(t+1,he+a[t]-a[t-1],h+1);
	dfs(t+1,he,h);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int abb=0;
	for(int i=1;i<n;i++){
		if(a[i]-1!=a[i-1]) abb=1;
	}
	if(abb==0){
		int i=0;
		for(i=0;;i++){
			cnt+=i;
			if(cnt>m) break;
		}
		cout<<i;
		return 0;
	}
	int ab=0;
	for(int i=1;i<n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]) ab=1;
	}
	if(ab==0){
		ll i=0,t=a[1]-a[0],he=0;
		for(i=0;;i+=t){
			cnt+=i;
			if(cnt>m) break;
			he++;
		}
		cout<<he;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
    return 0;
}
