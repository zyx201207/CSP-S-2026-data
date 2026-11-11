#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-67,andd;
int main(){
	freopen("and .in","r",stdin);
	freopen("and .out","w",stdout);
	cin >> n >> m;
	int a[n],b[m];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (a[j]>=maxx){
				maxx=a[j];
				a[j]=-67;
			}
		}
		b[i]=maxx;
		maxx=-67;
	}
	andd=b[0];
	for (int i=1;i<m;i++){
		andd=(andd&b[i]);
	}
	cout << andd;
	return 0;
}