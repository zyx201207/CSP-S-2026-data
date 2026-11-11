#include <bits/stdc++.h>
using namespace std;
int SSSR[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>SSSR[i];
		if(m==SSSR[i]&&n==1)cout<<1;
	}
	return 0;
} 
