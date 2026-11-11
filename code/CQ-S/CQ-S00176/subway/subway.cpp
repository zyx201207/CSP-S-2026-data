#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll M=1e12+10;
ll n,m,a[510][N],t[510][N],c,d,q,w[N];
ll h;
priority_queue<ll,vector<ll>,greater<> > pq;
bool A=1,B=1;
vector<ll> v[N];
vector<ll> v2[N];
ll op=1;
void bfs(int x,int y){
	queue<ll> q;
	q.push(x);
	while(q.size()){
		int k=q.front();
		q.pop();
		v2[op].push_back(k);
		for(int i=0;i<v[k].size();i++){
			if(v[k][i]==y){
				v2[op++].push_back(y);
			}
			else if(v[k][i]!=k){
				q.push(v[k][i]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		ll k1=0;
		cin>>k1;
		if(k1>2){
			A=0;
		}
		for(int j=1;j<=k1*2;j++){
			cin>>a[i][j]>>t[i][j];
		}
		v[a[i][1]].push_back(a[i][2]);
	}
	for(int i=1;i<=q;i++){
		ll x,y;cin>>x>>y;
		if(A){
			bfs(x,y);
			ll NaOH=M;
			for(int i=1;i<=op-1;i++){
				ll CuO=0;
				for(int Cl=0;Cl<v2[i].size();Cl++){
					CuO+=v2[i][Cl];
				}
				NaOH=min(CuO,NaOH);
			}
			cout<<NaOH<<"\n";
		}
	}
	return 0;
}
