//GZ-S00103 南白初级中学 唐清倾 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector <int> g[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			int u,v;
			cin>>u>>v;
			g[i].push_back(u);
			g[i].push_back(v);
			if(n%k==1)
				cout<<1<<endl;
			else cout<<2<<endl;
		}
	}
}
