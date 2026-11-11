#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int a[N],h[N],nxt[N],in[N],dp[N];
vector<int> v;
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		h[a[i]]=i;
		dp[a[i]]++;
	}
	for (int i=1;i<=n;i++){
		nxt[i]=h[a[i]];
		if (i==nxt[i]){
			nxt[i]=i+1;
			v.push_back(i);
		}
	}
	for (int u=0;u<v.size();u++){
		int i=v[u];
		if (nxt[nxt[i]]!=nxt[i]+1) nxt[i]=nxt[nxt[i]];
		if (in[i]==0) q.push(i);
		in[nxt[i]]++;
	}
	while (!q.empty()){
		int u=q.front();
		q.pop();
		dp[a[nxt[u]]]+=dp[a[u]];
		if (!(--in[nxt[u]])&&nxt[u]<=n) q.push(nxt[u]);
	}
	for (int i=1;i<=m;i++) cout<<dp[i]<<" ";
	cout<<endl;
	return 0;
}
