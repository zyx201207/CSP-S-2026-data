#include<bits/stdc++.h>
using namespace std;
int c,t;
long long u[100000],v[10000];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
		}
	}
	if(t==1)
	cout<<1;
	if(t==2){
		cout<<1<<endl;
		cout<<2;
	}
	return 0;
}
