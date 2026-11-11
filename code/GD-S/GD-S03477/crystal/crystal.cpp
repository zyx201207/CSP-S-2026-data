#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long m,n;
bool check(long long x){
	long long p=m;
	for(long long i=1;i<=x;i++){
		if(a[i]<a[x]){
			p-=a[x]-a[i];
		}
	}return p>=0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	long long l=1,r=n,mid,ans=1;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
