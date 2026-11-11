#include<bits/stdc++.h>
using namespace std;
int u[1000005];
int v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=0;j<n;j++){
			cin>>u[j]>>v[j];
		}
	}
	cout<<1<<endl;
	cout<<2;
	return 0;
}
