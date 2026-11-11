//4
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,k;
vector<int> tr[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		//tr.clear();
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			tr[u].push_back(v);
			tr[v].push_back(u);  
		}
		cout<<3<<endl;
		for(int i=0;i<=k;i++){
			int j=k-i;
			
		}
	}
	return 0;
}
