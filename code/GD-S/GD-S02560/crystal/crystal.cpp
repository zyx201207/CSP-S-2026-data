#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m;
ll a[500005];
ll pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int j=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		while(i>=j&&(a[i]*(i-j+1)-(pre[i]-pre[j-1]))>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
} 
