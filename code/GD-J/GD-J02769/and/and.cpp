#include<bits/stdc++.h>
using namespace std;
long long a[200005],m,n,b[200005],c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		c[i]=a[i];
		for(int j=i;j<n;j++){
			for(int k=j;k-j<=m;k++){
				c[i]=c[i]&a[k];
				
			}
			b[i]=max(b[i],c[i]);	
			
		}
	}
	cout<<b[n];
	return 0;
}
