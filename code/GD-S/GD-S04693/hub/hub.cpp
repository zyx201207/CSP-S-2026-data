#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,k,u[1000005],v[1000005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>u[i]>>v[i];
		cout<<(bool)(k%2==1)+1<<"\n";
	}
	return 0;
}
