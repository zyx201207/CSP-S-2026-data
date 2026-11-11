#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=5e5+5;

long long n,k,a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	long long cnt=0;
	int ans=0;
	while(l<=r&&r<=n){
		while(r<=n&&cnt<=k){
			ans=max(ans,r-l+1);
			r++;
			cnt+=(r-l)*(a[r]-a[r-1]);
		}
		while(l<=r&&cnt>k){
			cnt-=(a[r]-a[l]);
			l++;
		}
	}
	cout<<ans;
	return 0;
}
