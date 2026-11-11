#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009];
long long l,r,mid,ans;
bool check(int x){
	long long cnt=0;
	for(int i=1;i<=n+1-x;i++){
		int j=i+x-1;
		cnt=0;
		for(int k=i;k<=j;k++){
			cnt+=a[j]-a[k];
		}
		if(cnt<=m)return 1;
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
	sort(a+1,a+1+n);
	l=2,r=n;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(mid,ans);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
