#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[100000005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int j=2;j<=m;j++){
		if(a[j]==a[j-1]) cout<<0<<" ";
		else cout<<j<<" ";
	}
	return 0;
} 
