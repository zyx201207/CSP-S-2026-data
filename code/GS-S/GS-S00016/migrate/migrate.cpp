#include<iostream>
#include<algorithm>
#include<vector>
#define int long long 
using namespace std;
const int N=5e5+10;
int c,t;
int n,d;
int x[N];
int a[500][500];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int diff=x[2]-x[1];
		bool f=true;
		for(int i=1;i<=n;i++){
			if(x[2]-x[1]!=diff){
				f=false;
			}
		}
		if(f){
			if(d>=3*diff||n<=3){
				cout<<0<<'\n';
			}else{
				cout<<n-3<<'\n';
			}
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
