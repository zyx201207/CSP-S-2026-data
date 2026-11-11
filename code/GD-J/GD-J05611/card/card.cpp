#include<bits/stdc++.h>
using namespace std;
long long n,m,f[1000010],sum;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	
	for(int i=1;i<=m;i++)cout<<f[i];
	
	return 0;
}
