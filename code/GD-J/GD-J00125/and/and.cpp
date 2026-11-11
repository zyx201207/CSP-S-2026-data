#include<bits/stdc++.h> 
using namespace std;
int n;
int m;
int a[200008];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=1;i<m;i++){
		ans=(ans&a[n-1-i]);
	}
	cout <<ans;
	return 0;}
