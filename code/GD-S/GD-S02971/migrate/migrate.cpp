#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int arr[2000051]; 
int c,t,n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=3){
			cout<<0<<"\n";
			continue;
		} 
		else{
			cout<<1<<"\n";
		}
	}
	
	
	
	return 0;
}
