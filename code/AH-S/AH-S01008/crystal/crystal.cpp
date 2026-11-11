#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,b[500005],sum,tpas;
bool check(int x){
	sum=0;
	for(int i=1;i<x;i++){
		sum+=b[i];
	}
	sum-=(x-1)*b[x];
	tpas=sum;
	for(int i=x+1;i<=n;i++){
		sum-=b[i-x]-b[i-1];
		sum+=(x-1)*(b[i-1]-b[i]);
		tpas=min(tpas,sum);
	}
	if(tpas<=m){
		return 1; 
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
	for(int i=1;i<n;i++){
		b[i]=a[n]-a[i];
	}
	int l=0,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
