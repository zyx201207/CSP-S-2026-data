#include<bits/stdc++.h>
using namespace std;
int n,m,num,ans,a[100000],T,ccc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ccc>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1; i<=n; i++)
		cin>>a[i];
		cout<<n*(n-1)/2<<"\n";
	}
	return 0;
} 
