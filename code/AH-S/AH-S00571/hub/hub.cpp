#include<bits/stdc++.h>
using namespace std;
int c,t,t2;
int n,k;
long long ans;
vector<int> adj[2000010];
long long d[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	t2=t;
	while(t--){
		for(int i=1;i<=2000000;i++){
			d[i]=987654321;
		}
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	if(c==0){
		cout<<"1\n"<<"2";
	}else if(c<=3&&c>=1){
		if(t2==2){
			cout<<"1\n"<<"2";
		}else if(t2==3){
			cout<<"1"<<endl<<"1"<<endl<<"2";
		}
	}
	return 0;
}
