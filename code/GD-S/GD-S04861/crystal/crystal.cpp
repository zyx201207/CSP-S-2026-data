#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],f[500050];
bool check(long long x,long long y){
	for(int i=1;i<=x;i++){
		if(y<a[x]-a[i]){
			return false;
		} 
		else{
			y-=a[x]-a[i];
		}
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,mid=(l+r)/2,ans=0;
	while(l<=r){
		if(check(mid,m)==1){
			l=mid+1;
		}
		else{
			r=mid-1;
		} 
		mid=(l+r)/2;
	}
	cout<<mid;
	return 0;
}
