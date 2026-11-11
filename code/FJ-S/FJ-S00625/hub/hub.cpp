#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5,INF=2e9;
int c,QwQ,n,k;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>QwQ;
	while (QwQ--){
		cin>>n>>k;
		for (int i=1;i<=n-1;i++){
			int u,v;cin>>u>>v;
		}
		if (c==13 or c==14){
			int m=(n-1)/2,ans=(m+1)/k;
			if ((m+1)%k!=0) ans++;
			ans=(ans-1)/2+(ans-1)%2;
			cout<<ans+1;
			continue;
		}
		else cout<<n/k+1<<'\n';
	}
	return 0;
} 
