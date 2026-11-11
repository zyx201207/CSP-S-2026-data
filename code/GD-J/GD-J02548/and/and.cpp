#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin)
	//freopen("and.out","w",stdout)
	long long n,m,a[10010],b[10010],c,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d=a[i];
		for(int j=i;j<=i+m-1;j++){
			d=d and a[j+1];
		}
		b[i]=d;
	}
	c=b[1];
	for(int i=1;i<=n;i++){
		c=max(c,b[i+1]);
	}
	cout<<c;
	return 0;
}
