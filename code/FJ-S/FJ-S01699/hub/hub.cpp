#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[100005],v[100005];
int main(){
	cin>>c>>t;
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		int s;
		for(int i=1;i<=k;i++){
			cout<<i<<endl;
		}
	}
	return 0;
}
