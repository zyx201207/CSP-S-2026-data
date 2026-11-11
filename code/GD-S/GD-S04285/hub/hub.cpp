#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,x,y;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int j=1;j<n;j++)
			cin>>x>>y;
		cout<<k-1<<endl;
	}
	return 0;
}
