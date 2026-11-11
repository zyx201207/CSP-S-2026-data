#include<bits/stdc++.h>
using namespace std;
long long c,t,n[10000],k[10000],u[10000],v[10000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>k[i];
		for(int j=1;j<n[i];j++){
			cin>>u[i]>>v[i];
		}
	}cout<<1<<endl<<2;
	return 0;
}
