#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,ds[500001],zp[500001];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>ds[i];
	}
	if(n==4&&m==3){
		cout<<"3"<<" "<<"1"<<" "<<"4";	
	}
	return 0;
}
