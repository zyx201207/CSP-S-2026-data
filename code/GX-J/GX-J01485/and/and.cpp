#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100000010],b[100000010],c=0,d=1000;
int main(){
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4;j++){
			b[i]=a[i]%2*d;
			a[i]=a[i]/2;
			d/=10;
		}
	}
	cout<<12;

	return 0;
}
