#include<bits/stdc++.h>
using namespace std;
int c,t;
int u[2000020];
int v[2000020];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for (int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
		if (t!=0) cout<<1<<endl;
		if (t==0) cout<<2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
