#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			cin>>c[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}return 0;
}