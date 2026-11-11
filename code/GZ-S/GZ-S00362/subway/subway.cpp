//GZ-S00362 ·¶Ë¼Ñî 
#include<bits/stdc++.h>
#define f(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
#define V vector
#define p2 pair<int,int>
using namespace std;
int c,n,m,d,q;
V<V<int> >t,a,e;
V<int>w;
int fct(int A,int B){
	priority_queue<p2,V<p2>,greater<p2> >pq;
	V<int>dist(n+2,-1);
	pq.push({0,A});
	dist[A]=0;
	while(!pq.empty()){
		p2 d=pq.top();pq.pop();
		int du=d.second,dw=d.first;
		if(dw!=dist[du])continue;
		f(i,0,e[du].size()-1){
			int dt;
			f(j,0,a[e[du][i]].size()-1){
				if(a[e[du][i]][j]==du){
					dt=t[e[du][i]][j];
				}
			}
			f(j,0,a[e[du][i]].size()-1){
				int U=a[e[du][i]][j];
				if(U==du)continue;
				int W=t[e[du][i]][j]+dt;
				if(dist[U]>dw+W or dist[U]==-1){
					dist[U]=dw+W;
					pq.push({dist[U],U});
				}
			}
		}
	}
	return dist[B];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+2);
	t.resize(n+2);
	a.resize(n+2);
	e.resize(m+2);
	f(i,1,m){
		cin>>w[i];
	}
	f(i,1,n){
		int x,ya,yb;
		cin>>x;
		f(j,1,x){
			cin>>ya>>yb;
			a[i].push_back(ya);
			t[i].push_back(yb);
			e[ya].push_back(i);
		}
	}
	f(i,1,q){
		int x,y;
		cin>>x>>y;
		cout<<fct(x,y)+w[x]+w[y]<<'\n';
	}
	return 0;
}
