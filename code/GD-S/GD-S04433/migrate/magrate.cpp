#include<bits/stdc++.h>
using namespace std;

int c,t,x[2],dx;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>x[1]>>x[2];
	dx=x[2]-x[1];
	cout<<c-t-1;
	return 0;
} 
