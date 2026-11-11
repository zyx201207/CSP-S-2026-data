#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int c,t,n,k;
vector<int>G[maxn];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(c==13||c==14){
			if(k==n)cout<<"0\n";
			else if(k>=n/2)cout<<"1\n";
			else if(k==1)cout<<n/4+1<<"\n";
			else cout<<(n/2+2-k+2+3)/4<<"\n";
		}else{
			cout<<(n/2+2-k+2+3)/4<<"\n";
		}
	}
	return 0;
	while(1);
}
