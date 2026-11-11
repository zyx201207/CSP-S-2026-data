#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long t;
	cin>>t;
	for(long long i=0; i<t; i++) {
		long long sdf,dfs;
		cin>>sdf>>dfs;
		cout<<(dfs-sdf)/2;
	}
}
