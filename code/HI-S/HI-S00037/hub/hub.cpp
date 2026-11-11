#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000005],v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		int cnt=0;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<n/k-1<<endl;
	}
	return 0;
}
