#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=0,maxx=0,h;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n-m;i++){
		h=a[i];
		for(int j=1;j<m;j++){
			h&=a[i+j];
		}
		maxx=max(maxx,h);
	}
	cout<<maxx;
} 
