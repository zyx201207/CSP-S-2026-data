#include<bits/stdc++.h>
using namespace std;
const int MAX=2e6+10;
int c,t;
int n;
long long d;
long long k;
bool b=0;
long long x[MAX];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cin>>x[1]>>x[2];
		k=x[2]-x[1];
		for(int i=3;i<=n;i++){
			cin>>x[i];
			if(k!=x[i]-x[i-1])	b=1;
		}	
		if(b==0){
			if(2*k<=d){
				cout<<n-2+n-3;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		} 
	}
} 
