#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
long long a[maxn],s[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++)s[i] = s[i-1]+a[i];
	long long ans = 0;
	for(long long i = 1;i<=n;i++){
		long long l = 0,r = i+1;
		while(l+1<r){
			long long mid = (l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r = mid;
			else l = mid;
		}
		ans = max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
} 
