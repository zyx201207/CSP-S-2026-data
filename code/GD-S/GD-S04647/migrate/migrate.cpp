#include<bits/stdc++.h>
using namespace std;
int x[100000009];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	int sum=0;
	for(int i=1;i<=t+c;i++){
		cin>>n>>d>>x[i];
	}
	for(int i=1;i<=t;i++){
		sum=n/2;	
	}
	cout<<sum;
	 
	return 0;
}
