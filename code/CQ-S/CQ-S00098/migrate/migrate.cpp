#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int x[n+5];
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		cout<<n-x[i]<<endl;
	}
	return 0;
}
