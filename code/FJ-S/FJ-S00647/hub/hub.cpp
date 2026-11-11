#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u[j]>>v[j];
		}
		cout<<(k/2+k%2)/2+1<<"\n";
	}
	return 0;
}
