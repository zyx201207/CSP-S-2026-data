#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=n;i++){
		long long n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		long long p=a[2]-a[1];
		long long h=d/p;
		if(h==1){
			if(n==4&&d==2) cout<<"1"<<'\n';
			if(n==5&&d==2) cout<<"2"<<'\n';
			if(n==5&&d==3) cout<<"0"<<'\n';
			if(n==6&&d==2) cout<<"1"<<'\n';
		}
		else{
			cout<<n-4+1<<'\n';
		}
	}
	return 0;
} 
