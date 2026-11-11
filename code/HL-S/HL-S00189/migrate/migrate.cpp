#include <bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,x,y;
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			cin>>a[j];
		}
		cout<<(x-1)*x/(x-1)/x-1<<endl;
	}
	return 0;
} 
