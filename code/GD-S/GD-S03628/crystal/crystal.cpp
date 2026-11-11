#include<bits/stdc++.h>
using namespace std;
long long a[500005],l,r,mid,ans,n,m,t;
long long check(long long x){
	for(long long i=2;i<=n;i++){
		long long k=a[i];
		t=1;
		for(long long j=1;j<=n;j++){
			long long w=a[j];
			if(w<k){
				if(k-w<=m){
					w+=k-w;
					m-=k-w;
					t++;
				}
			}
		}
		if(t==mid){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
