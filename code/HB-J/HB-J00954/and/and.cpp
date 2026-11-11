#include<bits/stdc++.h>
using namespace std;
int n,m,a[200019];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	int b[m];
	sort(a,a+n+1);
	cout<<a[n];
		
	return 0;
	}
