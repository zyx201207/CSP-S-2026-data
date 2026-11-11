#include<bits/stdc++.h>;
using namespace std; 
long long x[10001];
long long y[10001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
   long long c,t,s=0,n,d;
   cin>>c>>t;
    for(int i=1;i<=t;i++){
    	cin>>n>>d;
    	for(int j=1;j<=n;j++){
    		cin>>x[i];
		}
		cout<<n%3;
	} 
	return 0;
} 
