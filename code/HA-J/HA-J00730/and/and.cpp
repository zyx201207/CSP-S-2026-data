#include <bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int a[N],b[N];
int n,m,q,o=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=1; 
	for(int i=1;i<=n;i++){
		b[p]=a[i];
		for(int j=i+1;j<=m;j++){
			b[p]=b[i]&a[j];
			p++;
		}
	}
	for(int i=1;i<=n;i++){
		q=max(q,b[i]);
	}
	cout<<q;
	return 0;
}
