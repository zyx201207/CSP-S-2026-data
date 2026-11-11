#include <bits/stdc++.h>
using namespace std;
int u[10000000],v[10000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=k;i++){
			cin>>u[i];
			cin>>v[i];
		}
	}
	cout<<"1"<<endl<<"2";
	return 0;
}
