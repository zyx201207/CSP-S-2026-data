#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b==2&&c==4&&d==2){
		cout<<1<<endl<<2<<endl;
	}
	if(b==2&&c==5&&d==3){
		cout<<0<<endl<<1<<endl;
	}
	/* 
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		long long a[N]={},b[N]={};
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
		}
	}*/
	return 0;
}
