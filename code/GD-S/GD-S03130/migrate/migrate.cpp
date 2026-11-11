#include<bits/stdc++.h>
using namespace std;
int n;
long long x[2000005]; 
unsigned long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		unsigned long long b=2*d-1;
		cout<<n-b<<endl;
	} 
	return 0;
} 
