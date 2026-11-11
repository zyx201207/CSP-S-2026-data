#include<bits/stdc++.h>
using namespace std;
int miku,n;
long long m,a[500010],sum[500010];
int find(int x){
	int l=1,r=x,mid,ans=x;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-sum[x]+sum[mid-1]<=m){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return x-ans+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	miku=0;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		miku=max(miku,find(i));
	}
	cout<<miku;
	return 0;
} 
