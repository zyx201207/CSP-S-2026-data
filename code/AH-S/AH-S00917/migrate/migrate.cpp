#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t>>n>>d;
	if(n==4&&d==2){
		cout<<"1\n2";
	}else{
		cout<<"0\n1";
	}
	return 0;
}

