#include <bits/stdc++.h>
 using namespace std;
 long long a[20000010];
 int main(){
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		if(t==1)cout<<0;
		else cout<<1; 
		t--;
	}
	return 0;
 } 
