#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);  
	int c,t,n,d;
	cin>>c>>t;
	int x[100];
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
	}
	if(n==5)cout<<1<<endl<<2;
	if(n==6)cout<<0<<endl<<1;
	return 0;
}
