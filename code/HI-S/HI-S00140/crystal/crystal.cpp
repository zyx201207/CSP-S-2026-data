#include<bits/stdc++.h>
using namespace std;
long long m,a[500005],n,l,r,ans,ll;
int check(int x){
	int sum=0;
	for(int i=ll;i<=n;i++){
		sum+=max((long long)0,a[x]-a[i]);
	}
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	l=1,r=n,ans=0;
	
	while(a[l+1]-a[l]>m){
		l++;
	}
	while(a[r]-a[r-1]>m){
		r--;
	}
	ll=l;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)<=m){
			ans=mid-ll+1;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

