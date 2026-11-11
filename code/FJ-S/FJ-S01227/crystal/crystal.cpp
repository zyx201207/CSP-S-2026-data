/*
 5 5
1 2 4 8 9
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[512345],l,r,mid,ans;
bool check(long long x){
	long long minn=1e18,sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(i>=x){
			sum-=a[i-x];
			minn=min(minn,a[i]*x-sum);
		}
	}return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=0,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}cout<<ans;
	return 0;
} 
