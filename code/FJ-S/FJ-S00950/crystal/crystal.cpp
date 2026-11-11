#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500005];
long long c[500005];
int n;
long long m;
long long fun(int l,int r){
	return (c[r-1]-c[l-1])-(l-1)*(a[r]-a[l]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c[i]=c[i-1]+(a[i+1]-a[i])*i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i-1,r=n+1;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(fun(i,mid)>m){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		ans=max(ans,r-i);
	}
	cout<<ans;
	return 0;
}

