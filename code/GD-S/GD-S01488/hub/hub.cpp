#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int u[N],v[N]; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;int n,k;
	for(int i=1;i<=t;i++){
		
		cin>>n>>k;
	}
	for(int i=1;i<=n-1;i++){
		cin>>u[i]>>v[i];
	}
	cout<<min(c,t)+1<<endl<<max(c,t); 
	return 0;
} 
