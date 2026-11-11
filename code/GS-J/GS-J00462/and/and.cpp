#include <bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i;
	cin >>n >>m;
	for(i=1;i<=n;i++){
		cin >>a[i];
	}
	for(i=1;i<=n;i++){
		for(int p=1;p<=m;p++){
			for(i=1;i<=n;i++){
			b[i]=+a[i] and a[i+1];
			}
		}
	}
	sort (b+1,b+n+1);
	cout << b[n]<<endl;
	return 0;
}
