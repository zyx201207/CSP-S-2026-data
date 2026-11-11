#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int n,ans;
long long m;
long long a[N],sum[N];
bool check(int x){
	long long cnt=0;
	for(int i=1;i<=n-x+1;i++){
		//cout<<"&"<<i<<endl;
		cnt=a[i+x-1]*x-sum[i+x-1]+sum[i-1];
		if(cnt<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
//	for(int i=1;i<=n-1;i++){
//		b[i]=a[i+1]-a[i];
//	}
	int l=0,r=n;
	while(l<=r){
		//cout<<"!"<<endl;
		int mid=(l+r)/2;
		if(check(mid)==1){
			l=mid+1;
			ans=mid;
		} else {
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/
/*
5 5
1 2 4 8 9

*/
