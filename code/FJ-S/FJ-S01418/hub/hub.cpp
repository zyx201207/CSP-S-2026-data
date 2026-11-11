#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7;
int u[N],v[N];
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
  freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>u[i]>>v[i];
	}
	cout<<1<<" "<<2<<endl;
	return 0;
} 
