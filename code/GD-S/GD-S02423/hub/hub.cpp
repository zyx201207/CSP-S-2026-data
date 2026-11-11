#include<bits/stdc++.h> 
using namespace std;
vector<int> G[1000005];
int n,k,c;

void work(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(k==n){ cout<<"0\n";return;}
	if(k==1) cout<<ceil((n+1)/4);
	else if(k>=(n-1)/2) cout<<1;
	else{
		double cnt=(k-1)/4;
		cout<<floor((n-1)/8-cnt+1);
	}
	cout<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>c>>T;
	while(T--){
		work();
	}
	return 0;
}
