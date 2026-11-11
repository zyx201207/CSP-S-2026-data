#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define int long long

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005];
	cin>>n>>m;
	for(int i=0;i<n-1;i++){
		cin>>a[i];
		for(int j=i+1;j<n;j++){
			if(n==m){
				cout<<a[i];
			}
			
		}
	}

	return 0;
} 
