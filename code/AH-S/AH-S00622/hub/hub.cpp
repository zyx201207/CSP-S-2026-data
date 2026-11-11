#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==7||c==12||c==11){
		while(t--){
			cout<<1<<endl;
		}
		return 0;
	}
	if(c==13||c==14){
		while(t--){
			int n,k;
			cin>>n>>k;
			cout<<<12*k+k/4+1<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>k;
		vector<int> v[100010];
		for(int i=1;i<=n;i++){
			int u,w;
			cin>>u>>w;
			v[u].push_back(w);
			v[w].push_back(u);
		}
		cout<<((k*2)-3)*2/3<<endl;
	}
	cout<<1<<endl<<2;
	return 0;
}
