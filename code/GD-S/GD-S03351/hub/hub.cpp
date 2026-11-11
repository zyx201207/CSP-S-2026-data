#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,u[1004],v[10005];
	cin>>c>>t;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i];
	}
	cout<<u[n]+v[k];
	 
	
	
	return 0;
}
