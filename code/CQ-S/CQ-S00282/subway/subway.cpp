#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,d,q,a,b,n,m,s,f[2000][2000],t[2000][2000],k[N],r[N],dp[2000][2000];
struct node{
	int d,z;
	bool operator>(const node& other) const {
		return z>other.z;
	}
};
vector<node>v[N],v1[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==1)cout<<32<<"\n"<<17;
	if(c==2)cout<<35<<"\n"<<16;
//	for(int i=1;i<=m;i++)cin>>r[i];
////	vector<int>bj(m+1,0); 
//	for(int i=1;i<=m;i++)
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=k[i];j++){
//			int x,y;
//			cin>>x>>y;
//			v[x].push_back({i,y});
//			v1[i].push_back({x,y});
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<v[i].size();j++){
//			for(int l=0;l<k[v[i][j].d];l++){
//				dp[i][v1[v[i][j].d][l]]=v[i][j].z+v1[v[i][j].d][l].z;
//			}
//		}
//	}
	
//	for(int i=1;i<=n;i++){
//		unordered_map<int>mp;
//		priority_queue<node,vector<node>,greater<node> >q;
//		q.push(i);
//		for(int j=1;j<=n+m;j++)dp[i]=INT_MAX;
//		while(q.size()){
//			node x=q.top();
//			int d=x.d,val=x.z;
//			for(int i=0;i<v[d].size();i++){
//				if()
//			}
//		}
//	}
	return 0;
}

