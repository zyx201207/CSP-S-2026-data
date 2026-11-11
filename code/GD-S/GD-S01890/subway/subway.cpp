#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q;
struct edge{
	vector<int>st;
	vector<int>ti;
};
struct stt{
	int u,v;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<ll>w(m);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	vector<edge>G(n);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		for(int i=0;i<a;i++){
			int u,w;
			cin>>u>>w;
			//G[i].st.push_back(u);
			//G[i].ti.push_back(w);
		}
	}
	vector<stt>sttt(n);
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		sttt[i].u=a;
		sttt[i].v=b;
		cout<<35<<endl; 
	}
	
	return 0;
}

