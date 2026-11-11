#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n;
long long m;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1,l=1;i<=n;i++){
		while(a[i]*(i-l+1)*1ll-(s[i]-s[l-1])>m)l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
