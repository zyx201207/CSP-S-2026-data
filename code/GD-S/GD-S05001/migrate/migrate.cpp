#include<bits/stdc++.h>
using namespace std;
int c,t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n;
		int jie=0;
		for(int i=1;i<=n;i++){
			jie+=i;
		}
		cout<<jie/2;
	}
	return 0;
} 
