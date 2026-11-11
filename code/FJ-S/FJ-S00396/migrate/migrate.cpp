#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool flag=true;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		c=x[2]-x[1];
		for(long long i=2;i<=n;i++){
			if(x[i]-x[i-1]!=c) flag=false;
		}
		if(flag){
			if(c>d){
				cout<<0<<endl;
			}
			else{
				cout<<d-c<<endl;
			}
		}
		else{
			cout<<0<<endl;
		}
	}
	return 0;
}
