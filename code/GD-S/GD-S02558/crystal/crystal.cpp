#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100005],num[100005];
bool check(int x){
	int cnt=1e18+1;
	for(int i=1;i<=n-x;i++){
		int nn=0;
		for(int j=0;j<x-1;j++){
			nn+=num[i+j]*(j+1);
		}
		cnt=min(cnt,nn);
	}
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=2;i<=n;i++){
			num[i-1]=a[i]-a[i-1];
		}
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid)){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<l-1;
	}else{
		int x=a[2]-a[1];
		int l=1,r=1e9;
		while(l<r){
			int mid=(l+r)/2;
			if(mid*(mid+1)*x/2>m){
				r=mid-1;
			}else{
				l=mid;
			}
		}
		cout<<l+1;
	}
	return 0;
} 
