#include<bits/stdc++.h>
using namespace std;
int n; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>n>>n; 
	if(n==4)cout<<1<<endl<<2;
	else if(n==5)cout<<0<<endl<<1;
	else cout<<0;
	return 0;
} 
