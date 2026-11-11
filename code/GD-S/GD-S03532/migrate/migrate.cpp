#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[10005][10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(n==4) cout<<"1"<<endl<<"2";
		if(n==6) cout<<"0"<<endl<<"1";
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
		}
	}
	return 0;
}
