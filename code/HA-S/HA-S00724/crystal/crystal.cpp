#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500005];
long long max_int=-1e12,min_int=1e12;
bool check(long long standard){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<standard){
			cnt+=(standard-a[i]);
			if(cnt>m) return false;
		}
	}
	if(cnt<=m) return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_int=max(max_int,a[i]);
		min_int=min(min_int,a[i]);
	}
	long long l=min_int,r=max_int;
	while(l<r){
		long long mid=(r-l+1)/2+l;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=l){
			ans++;	
		}
	}
	cout<<ans;
	return 0;
}

