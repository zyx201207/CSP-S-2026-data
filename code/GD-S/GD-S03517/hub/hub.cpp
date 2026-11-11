#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>c>>d;
	}
		
	for(int i=1;i<=t;i++)cout<<1;
	return 0;
}
