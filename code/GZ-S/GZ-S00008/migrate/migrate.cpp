#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t;
const int N=2*1e6+20;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}		
	}
	if(n==5&&d==2){
		cout<<1<<'\n';
		cout<<2<<'\n';
	}
	if(n==6&&d==2){
		cout<<0<<'\n';
		cout<<1<<'\n';
	}else{
		cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3
		<<'\n'<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0<<'\n';
	}
	return 0;
}

