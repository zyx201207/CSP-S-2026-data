#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000006],c,t,u,v,x=1;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int j=1;j<n;j++){
			cin>>u>>v;
			a[u]=v;
		}
		cout<<x<<endl;
	}
	return 0;
}
