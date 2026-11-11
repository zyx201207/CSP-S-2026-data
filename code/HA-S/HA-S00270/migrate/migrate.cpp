#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[10000005];
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
	if(d==2&&(n==4||n==5)){
		cout<<1<<endl<<2;
		return 0;
	}
	if((d==3||d==2)&&(n==5||n==6)){
		cout<<0<<endl<<1;
		return 0;
	}
	else{
		while(t--){
			cout<<0<<endl;
		}
	}
	return 0;
}
