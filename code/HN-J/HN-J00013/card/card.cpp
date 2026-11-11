#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],ans,ma;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ma;
		a[ma]=1;
	}
	ans=1;
	for(int i=1;i<=m;i++){
		cout<<i<<' ';
	}
	return 0;
} 
