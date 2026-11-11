#include <bits/stdc++.h>
using namespare std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100005],b[100005],c[100005],d[m+5];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			c[i]=a[i];
			if(a[i]==a[j]){
				c[i]=a[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
