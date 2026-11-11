#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000009],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	ans=a[n];
	while(--m){
		ans&=a[--n];
	}
	cout<<ans;
	return 0;
}
