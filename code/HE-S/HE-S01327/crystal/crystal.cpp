#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long cnt=0;
bool check(long long x,long long m){
	long long su=0;
	for(int i=0;i<n;i++){
		if(a[i]<x){
			su+=x-a[i];
		}
	}
	return su<=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long l=0,r=n-1;
	long long ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid,m)){
			long long cnt2=0;
			for(int i=0;i<n;i++){
				if(a[i]<=mid){
					cnt2++;
				}
			}
			ans=max(ans,cnt2);
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
