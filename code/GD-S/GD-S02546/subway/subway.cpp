#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+9;
const int N = 509;
const int Q = 1e5+9;
using ll = long long;
ll c,n,m,d,q;
ll w[M];
vector<ll>a[N];
vector<ll>t[N];
int k[N];
int plan[Q][3];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=k;i++){
			int a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
			
		}		
			
	}
	
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		plan[i][1] = u;
		plan[i][2] = v;
	}
	
	for(int i=1;i<=q;i++){
		cout<<w[plan[i][1]]+w[plan[i][2]];
	}
	
	return 0;
} 
