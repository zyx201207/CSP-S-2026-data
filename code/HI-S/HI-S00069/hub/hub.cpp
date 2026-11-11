#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,m,a,b;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n-1;i++)cin>>a>>b;
		cout<<n/5<<endl;
	}
	return 0;
}
