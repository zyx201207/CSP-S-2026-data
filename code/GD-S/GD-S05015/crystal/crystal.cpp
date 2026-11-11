#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N];
long long c[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)c[i]=a[i+1]-a[i];
	long long sum=0;
	for(int l=0,r=0;r<n;){
		r++;
		sum+=c[r]*(r-l);
		while(sum>m){
			l++;
			sum-=a[r+1]-a[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

