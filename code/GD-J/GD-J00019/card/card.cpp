#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<m,n-m,n;
	return 0;
}
