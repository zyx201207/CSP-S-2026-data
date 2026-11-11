//GZ-J00152  遵义市第四中学 曾皓宇
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],t[200005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int z=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]<a[i-1]) {
			z=1;
		}
	}
	if(z==0) {
		int h=a[1];
		for(int i=2; i<=n; i++) {
			if(a[i-1]!=a[i]){
				t[h]=i-1;
				h++;
			}
		}
		for(int i=1;i<=m;i++){
			if(i==m){
				cout<<n;
				return 0;
			}
			cout<<t[i]<<" ";
		}
	}else if(m==1){
		cout<<n;
		return 0;
	}else if(m==2){
		for(int i=1; i<=n; i++) {
			t[a[i]]++;
			if(i==n){
				t[a[i]]=n;
			}
		}
		cout<<t[1]<<" "<<t[2];
	}
	return 0;
}
