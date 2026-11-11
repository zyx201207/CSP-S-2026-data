#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005],f[300005],d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		a[d[i]]++;
		b[d[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int k=b[i];
		while(k<=n){
			c[d[k]]+=a[i];
			k=b[d[k]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
	
}
/*
4 3
1 2 1 3


*/
