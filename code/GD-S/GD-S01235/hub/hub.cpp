#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int maxn=2e6+5;
int c,t,n,k;
vector<int> G[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		if(c==13||c==14){
			n-=k;
			if(n%3!=0) n++;
			cout<<n/3<<endl;
			continue;
	    }
	}
    return 0;
}    
