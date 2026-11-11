#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k>=n/2) cout<<"1\n";
		else cout<<n/2/(k+1)+1<<'\n';
	}
	return 0;
}
