#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	 {
	 	if(t%2==0) cout<<i<<"\n";
	 	else
	 	 {
	 	 	if(i%2==1) cout<<i/2+1<<"\n";
	 	 	else cout<<i/2<<"\n";
		  }
	 }
	return 0;
}
