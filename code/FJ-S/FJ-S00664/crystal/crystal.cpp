#include<bits/stdc++.h>
using namespace std;
long long typedef ll;
const ll N=5e5+5;
ll n,a[N],m,pre[N],ans,t[N],tt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		t[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++)
		tt[i]=t[i]*(i-1);
	for(int i=2;i<=n;i++)
		pre[i]=pre[i-1]+tt[i];
	for(ll i=1;i<=n;i++)
		if(pre[i]<=m) ans=max(ans,i);
	cout<<ans;
	return 0;
}
