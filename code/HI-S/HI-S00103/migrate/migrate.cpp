#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		cout<<n/d<<"\n";
	}
	return 0;
}
