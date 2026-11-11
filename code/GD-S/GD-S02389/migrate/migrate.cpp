#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int qw=1;qw<=t;qw++){
	
	long long n,d;
	long long x[n+5];
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	cin>>x[i];
	long long dis=x[2]-x[1],cnt=0;
	long long h=0;

	if(dis>d)cout<<"0";
	if(dis==d)cout<<"0";}
	return 0;
	
}
