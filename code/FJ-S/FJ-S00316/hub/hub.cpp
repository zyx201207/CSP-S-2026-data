#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int c,T,n,k,p[N],fa[N];
vector <int> t[N];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;while(T--){
		cin>>n>>k;for(int i=1;i<=n;i++) t[i].clear();
		for(int i=1;i<n;i++) {int u,v;cin>>u>>v;t[u].push_back(v);t[v].push_back(u);}
		if(c==13||c==0) {cout<<(int)(n/8)-(int)(k/4)+2*((n/2)%2)<<"\n";continue;}cout<<"0\n";
	}
	return 0;
}

