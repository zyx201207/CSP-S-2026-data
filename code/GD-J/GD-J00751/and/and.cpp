#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ee;
	int maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ee=a[i]&a[j];
			maxx=max(maxx,ee);
		}
	}
	cout<<maxx;
	return 0;
} 
