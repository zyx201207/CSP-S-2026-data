#include<bits/stdc++.h>
using namespace std;
int n,sum,ans=-1,r,l;
long long m,a[500005];
bool check(long long mid){
	long long m1=m;
	sum=1;
	for(int i=(r-l+1)/2+l-1;i>=1;i--){
		if(mid-a[i]<=m1){
			m1=m1-(mid-a[i]);
			sum++;
		}
		else{
		    break;
		}
	}
	if(sum>=ans){
		ans=sum;
		return 1;
	}
	else{
		return 0;
	}
}
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	l=1,r=n;
	while(l<=r){
		long long mid=a[(r-l+1)/2+l];
		if(check(mid)){
			l=(r-l+1)/2+l+1;
		}
		else{
			r=(r-l+1)/2+l-1;
		}
	}
	cout<<ans;
	return 0;
}
 
