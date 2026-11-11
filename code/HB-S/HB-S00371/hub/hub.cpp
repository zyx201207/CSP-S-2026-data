#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int u[N],v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];	
		}
		cout<<abs(n-2*k)<<endl;
	}
	return 0;
}
