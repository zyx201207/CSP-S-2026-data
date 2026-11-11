#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n; cin>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) s[i]=(a[i+1]-a[i])*i;
	long long l=1,r=1,rr=0;
	long long sum=0;
	long long ans=0;
	while(l<=r&&r<n){
		if(rr!=r){
			sum+=s[r];
		}
		if(sum>m){
			ans=max(ans,r-l+1);
			sum-=s[l];
			l++;
			rr=r;
		}
		else rr=r,r++;
		if(l>r) swap(l,r);
	}
	printf("%lld",ans);
	return 0; 
}
