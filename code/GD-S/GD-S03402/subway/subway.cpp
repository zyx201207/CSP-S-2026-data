#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e6;
long long c,n,m,d,q,sum=0;
long long w[MAXN],k[MAXN],t[MAXN];
vector<long long> edge[MAXN];
void bfs(int s,int e)
{
	queue<long long> pq;
	pq.push(s);
	while(!pq.empty()){
		int cnt=pq.front();
		for(int i=0;i<edge[cnt].size();i++){
			int v=edge[cnt][i];
			if(edge[cnt][i]!=e){
				int cnt=pq.front();
				pq.pop();
				pq.push(edge[cnt][i]);
				sum++;
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
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			cin>>k[j]>>t[j];
			if(j>1){
				edge[k[j]].push_back(k[j-1]);
				edge[k[j-1]].push_back(k[j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		sum=0;
		bfs(s,e);
		cout<<sum;
	}
	return 0;
}
