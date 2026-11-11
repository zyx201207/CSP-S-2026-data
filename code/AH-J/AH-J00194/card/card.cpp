#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000001],t[1000001];
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	
	for(int i=1;i<=m;i++){
		cout<<t[i];
	}
	return 0;
}
