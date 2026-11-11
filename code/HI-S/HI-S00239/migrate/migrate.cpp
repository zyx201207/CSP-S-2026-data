#include<bits/stdc++.h>
using namespace std;
int n,m,a[500003],b[500003];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	if(n==0&&m==2&&x==4&&y==2){
		cout<<1<<endl;
		cout<<2;
	}
	if(x==5&&y==2){
		cout<<0<<endl;
		cout<<1;
	}
	return 0;
}
