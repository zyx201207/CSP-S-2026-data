#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int sum[300010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(a[j]!=a[j-i]){
				sum[i]++;
			}
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<sum[i]<<" ";
	}
	return 0;
}
