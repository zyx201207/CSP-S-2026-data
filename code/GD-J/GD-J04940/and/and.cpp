#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[200005];

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		hh(a[i],i+1);
	}
	cout<<a[1]&a[2];
	return 0;	
} 
