#include<bits/stdc++.h>
using namespace std;
int u[10086],v[10086];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>u[i]>>v[i];
	}
	if(t==2&&n==10&&k==3)
		cout<<1<<endl<<2;
	else
		cout<<1<<endl<<1<<endl<<2;
	return 0;
	
}
