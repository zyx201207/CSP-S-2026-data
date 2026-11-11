#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[100000000],b;
int dfs(){
} 
int main(){
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a;
	int mx=-1,mi=2100000000;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>mx) mx=a;
		if(a<mi) mi=a;
	} 
	if(m==1)cout<<mx;
	else if(m==n) cout<<mi;
	else cout<<0;
	return 0;
	
} 
