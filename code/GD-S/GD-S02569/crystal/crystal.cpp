#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long ans;

bool check(int mid){
	long long x=0;
	for(int i=1;i<mid;i++){
		x+=(a[mid]-a[i]);
		if(x>m)return 0;
	}
	return 1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=1,r=n;
	sort(a+1,a+n+1);
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
