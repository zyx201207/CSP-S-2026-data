#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FN "crystal"
int n,l,ans;
ll ts,m,a[500005];
int main(){
	freopen(FN".in","r",stdin);
	freopen(FN".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=n+1;
	for(int i=n;i>0;i--){
		if(l<=i){
			ts-=(i-l+1)*(a[i+1]-a[i]);
		}
		while(l>1&&ts+(a[i]-a[l-1])<=m)ts+=a[i]-a[--l];
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
//5min
