#include<bits/stdc++.h>
using namespace std;//0 or 16
const int N=1e6+67,M=5e3+67,inf=0x3f3f3f3f;
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	
	return 0;
}
