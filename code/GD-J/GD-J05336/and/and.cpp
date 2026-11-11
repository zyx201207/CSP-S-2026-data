#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long a[200005]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	long long ma=-1e9,c,t,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<m;j++){
			c=(a[i]&a[i+1]);
		}
		ma=max(ma,c);
	}
	cout<<ma;
	return 0;
} 
