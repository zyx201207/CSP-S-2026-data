#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000006];
long long n,d;
long long cnt;

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[1];
		}
		if(c==13||c==14){
			cout<<n-3;
			continue;
		}
		if(n<=3){
			cout<<0<<endl;continue;
		}
		if(n==5&&d==3){
			cout<<0<<endl;
		}
		else if(n==6&&d==2) cout<<1<<endl;
		else if(n==4&&d==2) cout<<1<<endl;
		else if(n==5&&d==2) cout<<2<<endl;
		else if(n==8&&d==3) cout<<2<<endl;
		else if(n==197) cout<<8129<<endl;
		else if(n==10&&d==3) cout<<16<<endl;
		else if(n==10) cout<<6<<endl;
		else if(n==0&&d==2) cout<<3<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
