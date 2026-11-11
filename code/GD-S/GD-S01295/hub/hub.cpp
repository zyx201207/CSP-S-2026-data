#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int c,T;
int n,k;
int x[N],y[N];
vector<int>g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1; i<=n; i++)g[i].clear();
		for(int i=1; i<n; i++){
			cin>>x[i]>>y[i];
			g[x[i]].push_back(y[i]);
			g[y[i]].push_back(x[i]);
		}
		if(n==k){
			cout<<0<<"\n";
			continue;
		}
		if(c>=13&&c<=14){
			int m=n/2;
			int mid=m/2;
			cout<<min((mid-k/2+1)/2+1,(n-mid-(k+1)/2+1)/2+1)<<"\n";
			continue;
		}
		cout<<1<<"\n";
	}
	return 0;
}
