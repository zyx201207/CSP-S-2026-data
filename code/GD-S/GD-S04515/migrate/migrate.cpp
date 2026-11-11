#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long y,t;
	cin>>y>>t;
	for(long long p=1;p<=t;p++){
		long long n,m;
		cin>>n>>m;
		long long a[n+1]={};
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n/(m*m)<<endl;
	}
	return 0;
}
