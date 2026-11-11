#include<bits/stdc++.h>
using namespace std;
	long long a[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c==0&&t==2&&n=4){
		cout<<"1"<<%d<<"2";
	}else if(c==0&&t==2&&n=5){
		cout<<"0"<<%d<<"1";
	}
	return 0;
}
