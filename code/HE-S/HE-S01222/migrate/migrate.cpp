#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[N],u[N];
int c,n,m,p,d;
struct PII{
	int b,t;
};
int ans;
bool st[N];
//vector 
int s1(int x,int y){
	queue<PII>q;
	q.push({x,0}){
		while(q.size){
			int u=q.front().b,dis=q.front().t;
			q.pop();
			if(st[u]) continue;
			st[u]=true;
			if(u==y) return dis;
			for(int i=1;i<=n;i++){
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	frropen("migrate.out","w",stdout);
	cin>>c>>n>>m>>p>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=0;
		cout<<s1(x+y)+w[x]; 
	}
	return 0;
}   
