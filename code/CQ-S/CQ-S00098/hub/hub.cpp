#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int u[n+5],v[n+5];
		for(int j=1;j<n;j++){
			cin>>u[j]>>v[j];
		}
		cout<<u[i]-k<<endl;
	}
	return 0;
}
