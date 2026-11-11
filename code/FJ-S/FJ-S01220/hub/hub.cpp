#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mx=1e6;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		int u[mx],v[mx];
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
		cout<<k%2+1<<endl;
	}
	return 0;
}

