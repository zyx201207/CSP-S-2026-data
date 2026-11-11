#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],h[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) h[i]=h[i-1]+a[i];
	long long j=1,ans=0;
	for(long long i=1;i<=n;i++){
		while(a[j]*(j-i)-h[j-1]+h[i-1]<=m&&j<n){
			ans=max(j-i+1,ans);
			j++;
		}
		if(j==n) break;
	}
	cout<<ans;
	return 0;
}
