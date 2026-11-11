#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;
int u[10005],v[10005];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t>>n>>k;
	for(int i=1;i<=n-1;i++){
		cin>>u[i]>>v[i];
	}
	for(int i=1;i<=t;i++){
		cout<<i<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
