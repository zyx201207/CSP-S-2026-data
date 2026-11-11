#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(long long i=0,x;i<n;i++){
			cin>>x;
		}
		cout<<n*(n-1)/2<<"\n";
	}
	return 0;
}

