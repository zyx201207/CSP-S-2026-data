#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MaxN=5e5+100;

int n,ans;
ll m;
ll a[MaxN],s[MaxN];

int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int l=1,r=1;r<=n;r++){
		while(l<=r&&a[r]*(r-l)-s[r-1]+s[l-1]>m)l++;
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	
	return 0;
} 
