#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long n,m;
long long f(long long mid){
	long long num=0,h=m;
	for(long long i=n-1;i>=0;i--){
		if(a[i]<=mid){
			if(h>=mid-a[i]){
				num++;
				h-=mid-a[i];
			}
		}
	}
	return num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int oo=1;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=i+1) oo=0;
	}
	if(oo=0){
		long long sum=1,x=1,l=m;
		while(l){
			l-=x;
			x++;
			if(l>=0) sum++;
		}
		cout<<sum;
		return 0;
	}
	sort(a,a+n);
	long long ans=-1;
	for(long long i=a[n-1];i>=a[0];i--){
		ans=max(ans,f(i));
	}
	cout<<ans;
	return 0;
}
