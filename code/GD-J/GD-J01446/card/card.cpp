#include<bits/stdc++.h>
using namespace std;
int a[300005];
int b[300005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		a[k]=i;
		b[k]++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]/2+(b[i]%2)+a[i]<<' ';
	}
	return 0;
} 
