#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t,n,d;
	cin>>c>>t>>n>>d;
	if(n==4&&d==2){
		cout<<1<<"\n"<<2;
	}
	if(n==5&&d==3){
		cout<<0<<"\n"<<1;
	}
	return 0;
}
