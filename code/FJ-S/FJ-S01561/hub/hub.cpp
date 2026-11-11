#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using pii = pair<int,int> ;
int C,T;
int n,k;
vector<int>v[2000100];
int d[2000100];
void dfs(int x,int fa){
	for(auto i:v[x]){
		if(i==fa)continue;
		d[i]=d[x]+1;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)d[i]=0;
		for(int i=1;i<n;i++){
			int l,r;
			cin>>l>>r;
			v[l].push_back(r);
			v[r].push_back(l);
		}
		dfs(1,0);
		int mx=-INF;
		for(int i=1;i<=n;i++){
			mx=max(mx,d[i]);
		}
		mx=mx/(k/2);
		cout<<mx<<endl;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5

10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
