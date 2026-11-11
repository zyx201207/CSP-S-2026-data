#include <bits/stdc++.h>
using namespace std;
int n,m,a[500008],mn[500008];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=m;i++){
		cout<<n-i+1<<" ";
	}
	return 0;
} 
