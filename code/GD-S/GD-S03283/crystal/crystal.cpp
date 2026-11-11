#include<bits/stdc++.h>
using namespace std;
long long a[600001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	long long ans=1,l=1,k=0,b=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b=a[i]-a[i-1];
		k+=(i-l)*b;
		while(k>m){
			l++;
			k-=(a[i]-a[l]);
		}
		ans=max(ans,(i-l+1));
	}cout<<ans;
	return 0;
} 
