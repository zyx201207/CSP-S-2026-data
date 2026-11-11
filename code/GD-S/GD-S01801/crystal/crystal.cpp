#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n;
long long m;
long long a[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l = 1,r = 1,ans = 1;
	long long cnt = 0;
	while(r<n){
		r++;
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=(a[r]-a[l]);
			l++;
		}
		ans = max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
