#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[200010];
int ans=0;
void sub(int n,int m,int rst){
	if(m==0){
		ans=max(rst,ans);
		return;
	}
	sub(n-1,m-1,rst&a[n-1]);
	if(n>=m){
		sub(n-1,m,rst);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<22){
		sub(n,m,1073741823);
	}else{
		sort(a,a+n);
		ans=a[n-1];
		for(int i=n-2;i>=n-m;i--){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
