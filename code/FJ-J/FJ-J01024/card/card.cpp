#include <bits/stdc++.h>
using namespace std;
bool b[1000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,a[1000001],m,j=0,d[1000001],k[1000001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d[i-j]=a[i];
		b[i]=1;k[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cout<<k[a[i]]++;
	}
}
