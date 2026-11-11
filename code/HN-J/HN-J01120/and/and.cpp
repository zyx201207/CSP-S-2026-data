#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001],k[31]={1},l,minn=2147483647,rst[200001],sa,ct;
bool flag=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=30;i++){
		k[i]=k[i-1]*2;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long p=upper_bound(k+1,k+31,a[i])-k;
		long long nd=k[p]-a[i];
		if(minn>nd){
			minn=nd;
			sa=k[p];
		}
	}
	for(int i=1;i<=n;i++){
		rst[i]=a[i]%sa;
	}
	sort(rst+1,rst+n+1);
	long long asd=rst[n];
	for(int i=n-1;i>=n-m+1;i--){
		asd&=rst[i];
	}
	cout<<asd;
	return 0;
}

