#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+2],t[m+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) if(t[a[j]]!=i) t[a[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
} 
