#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000005];
int b[10000005];
string s[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		b[i]=a[i];
	} 
	cout<<b[n]; 
	return 0;
} 
