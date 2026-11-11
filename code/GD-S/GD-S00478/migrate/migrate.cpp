#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		cout<<(n-1)/2<<endl;
	}
	return 0;
} 
