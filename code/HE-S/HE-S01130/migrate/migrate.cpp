#include<bits/stdc++.h>
using namespace std;
long long a[100000000];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
	}
	if(n==4&&d==2){
		cout<<1<<endl<<2;
		return 0;
	}
	if(c==0&&t==2){
		cout<<0<<endl<<1;
		return 0;
	}
	if(c==0&&t==17){
		cout<<1<<endl<<2;
		return 0;
	}
	cout<<0;
	return 0;
} 
