#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans;
long long a[N];
bool pd(int mid){
	long long x=m;
	for(int i=1;i<=mid;i++){
		if(a[i]==a[mid]){
			break;
		}
		x=x-(a[mid]-a[i]);
		if(x<0){
			break;
		}
	}
	if(x<0){
		return 0;
	}return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(pd(mid)){
			l=mid+1;
			ans=max(mid,ans);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
