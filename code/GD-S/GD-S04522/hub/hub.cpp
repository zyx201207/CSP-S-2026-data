#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u[1000003],v[1000003];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>k;
		if(p!=1){
			memset(u,0,sizeof(u));
			memset(v,0,sizeof(v));
		}	
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
			if(u[i]>n||v[i]>n){
				u[i]=0,v[i]=0;
			}
		}
		cout<<u[p]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
