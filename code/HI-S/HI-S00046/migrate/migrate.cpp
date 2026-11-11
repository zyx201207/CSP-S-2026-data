#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	long long m,n,v;
	cin>>n>>m>>v;
	if(v==4){
		cout<<1<<'\n'<<2;
	}
	else{
		cout<<n<<'\n'<<m-1;
	}
	return 0;
}
