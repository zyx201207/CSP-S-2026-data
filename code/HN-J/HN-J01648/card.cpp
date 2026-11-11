#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[300010],c[500010],d[300010];
int main(  ){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i+1;
	}
	for(int i=1;i<=n;i++){
		c[i]++;
		d[a[i]]+=c[i];
		c[b[a[i]]]+=c[i];
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
} 
