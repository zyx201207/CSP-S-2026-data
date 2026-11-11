#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],s[maxn],ans;
int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]-a[i-1];
	s[1]=0;
	for(long long l=1,r=0,x=0;l<=n;l++){
		x-=a[r]-a[l-1];
		while(r<n&&x+(r-l+1)*s[r+1]<=m)x+=(r-l+1)*s[++r];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
