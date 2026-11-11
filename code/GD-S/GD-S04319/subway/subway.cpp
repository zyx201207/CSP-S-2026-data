#include<bits/stdc++.h>
using namespace std;
int w[514514],q,c,n,m,d,a,b,inqueue[514514];
int pre[514];
struct node{
	int from,to,t;
};
void teshua(){
	queue<node>q;
	vector<node>dis[514];
	for(int i=1;i<=500;i++)pre[i]=1e9;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,ai,at,bi,bt;
		cin>>k>>ai>>at>>bi>>bt;
		dis[ai].push_back(node{ai,bi,at+bt});
		dis[bi].push_back(node{bi,ai,at+bt});
	}for(int i=1;i<=q;i++){
		cin>>a>>b;
		q.push(a);
		while(!q.empty()){
			node lu=q.front();
			q.pop();
			for(int i=1;i<=dis[lu.from].size();i++){
				
			}
			
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=3){
		
	}
	if((c>=7)&&(c<=11)){
		teshua();
	}
	return 0;
}
