#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],s[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int pos=1;
	for(int i=1;i<=n;i++){
		while(1ll*(i-pos+1)*a[i] - s[i]+s[pos-1]>m)pos++;
		ans=max(ans,i-pos+1);
	}cout<<ans;
	return 0;
}
