#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	unsigned long long c,t,n,k;
	unsigned long long u[2000010],v[2000010];
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<u[i]<<endl;
	}
	return 0;
}
