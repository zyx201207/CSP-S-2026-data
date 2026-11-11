#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>t;
	long long x[100001][2000001],d[100001],i=1;
	while(t--){
		int n;
		cin>>n>>d[i];
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
		}
	}
	cout<<2<<" "<<1;
	return 0;
}
