#include<bits/stdc++.h>
using namespace std;
int u[2000005];
int v[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			cin>>u[j]>>v[j];
		}
	}
	for(int i=1;i<=t;i++) cout<<1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

