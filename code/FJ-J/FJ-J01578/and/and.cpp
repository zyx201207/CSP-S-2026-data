#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long int n,m,a[N];
long long int del(int x){
	int res=a[1];
	for(int i=2;i<=n;i++){
		if(i!=x){
			res&=a[i];
		}
	}
	return res;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		long long int s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==1){
		long long int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>ans){
				ans=a[i];
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long int ans=0;
		for(int i=1;i<=n;i++){
			if(del(i)>ans){
				ans=del(i);
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

