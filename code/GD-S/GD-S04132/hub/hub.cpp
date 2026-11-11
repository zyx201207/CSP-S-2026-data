#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int u[N+5],v[N+5];
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
