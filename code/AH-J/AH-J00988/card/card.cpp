#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++){
			if (b[a[j]]==0) {b[a[j]]++;}
			else for (int k=j-1;k>=i;k--) {
				if (a[k]!=a[j] and b[a[k]]) b[a[k]]--;
				else break;
			}
			
	
		}
		
		for (int j=1;j<=m;j++) {
			if (b[j]){
			c[j]++;
			b[j]=0;
			}
		}
	}
	for (int j=1;j<=m;j++) {
			cout<<c[j]<<" ";
		}
	return 0;
}
