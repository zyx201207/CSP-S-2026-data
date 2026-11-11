#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],ans;
bool check(long long x){
	long long sum=0;
	for(int i=1;i<x;i++){
		sum+=a[i];
	}for(int i=x;i<=n;i++){
		sum-=a[i-x],sum+=a[i];
		long long num=a[i]*x;
		if(num-sum<=m)return 1;
	}return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}cout<<ans;
	return 0;
} 
