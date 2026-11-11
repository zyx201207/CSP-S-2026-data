#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d>=x[n]-x[1]){
			cout<<0<<"\n";
			continue;
		}
		if(d<x[2]-x[1]){
			cout<<0<<"\n";
			continue;
		}
		long long cha=x[2]-x[1],ge=(d/cha)*2;
		if(d/cha==1)
			cout<<"0"<<"\n";
		else
			cout<<n-ge+1<<"\n";
	}
	return 0;
}
