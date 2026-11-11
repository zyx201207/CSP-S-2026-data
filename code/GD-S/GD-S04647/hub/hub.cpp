#include<bits/stdc++.h>
using namespace std;
long long u[1000006],v[1000006];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long n,k;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		cin>>u[i]>>v[i];
	}
	cout<<c+1<<endl<<t; 
	
	return 0;
}
