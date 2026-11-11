#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn,k;
long long a[550000];
bool check(long long mid){
	long long k=0;
	for(int i=1;i<=n;i++){
		if(mid>=a[i]){
			k+=mid-a[i];
		}
	}
	return k<=m;
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n,cmp);
	long long l=1,r=maxn,ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(ans>=a[i]&&m>=ans-a[i]){
			k++;
			m=m-(ans-a[i]);
		}
	}
	cout<<k;
	return 0;
}
