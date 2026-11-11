#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		int d;
		cin>>d;
		int x[200010*10];
		for(int j=1;j<=n;j++){
			cin>>x[j*1];
			x[j]/=1;
		}
		cout<<i<<endl;
	}
	return 0;
}
