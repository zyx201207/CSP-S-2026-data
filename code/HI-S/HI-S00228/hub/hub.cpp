#include<bits/stdc++.h>
using namespace std;

//¿ª longlong!!!!! 

int c,t;
int n,k;
vector<int> map0[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	if(c){
		while(t--){
			cin>>n>>k;
			int u,v;
			for(int i=0;i<n;i++){
				cin>>u>>v;
				map0[u].push_back(v);
				map0[v].push_back(u);
			}
			
		}
	}
	
    return 0;
}

