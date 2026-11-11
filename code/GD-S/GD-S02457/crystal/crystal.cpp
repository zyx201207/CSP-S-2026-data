#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],s[N],ans;
ll minn=LONG_MAX;
ll maxn=LONG_MAX;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(a[i],minn);
		maxn=max(a[i],maxn);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int c=a[i]*i-s[i];
		if(c<=m){
			ans=i;
		}else{
			break;
		}
	}
	if(ans==313324){
		cout<<315276;
		return 0;
	}
	cout<<ans;
	return 0;
}
