#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long k=0;
	long long mx=0;
	for(long long i=n-1;i>=0;i--){
		k=0;
		for(int j=0;j<i;j++){
			k+=a[i]-a[j];
			
		}
		if(k<=m){
			mx=max(i+1,mx);
		}
	}
	cout<<mx;
} 
