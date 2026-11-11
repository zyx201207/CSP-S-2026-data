#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e15;

int c,T;
int n,d,ij;
int a[2000006];
struct h{
	int x,y,e;
}o[2000006];
int fe[2000006];

int s[2000006];
int p[2000006];
int vis[2000006];
struct H{int tu,tsum;};
priority_queue<H> pq;
bool operator <(H t1,H t2){
	return t1.tsum>t2.tsum;
}

void add(int sx,int sy){
	ij++;
	o[ij].x=sx;
	o[ij].y=sy;
	o[ij].e=fe[o[ij].x];
	fe[o[ij].x]=ij;
	return;
}

void dij(int px){
	for(int i=1;i<=n;i++){
		s[i]=inf,p[i]=0,vis[i]=0;
	}
	s[px]=0;
	p[px]=1;
	pq.push({px,0});
	while(!pq.empty()){
		H u=pq.top();
		pq.pop();
		if(vis[u.tu]==1)continue;
		else vis[u.tu]=1;
		for(int j=fe[u.tu];j;j=o[j].e){
			int v=o[j].y;
			if(s[u.tu]+1==s[v]){
				p[v]+=p[u.tu]; 
			}else if(s[u.tu]+1<s[v]){
				s[v]=s[u.tu]+1;
				p[v]=p[u.tu];
				pq.push({v,s[v]});
			}
		}
	}
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ij=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			fe[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					add(i,j);
				}else{
					break;
				}
			}
		}
		
		int ans=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=i+1;j<=n;j++)ans+=(p[j]==2);
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
