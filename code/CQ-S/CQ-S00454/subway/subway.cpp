#include<bits/stdc++.h>
using namespace std;
const int N=2000;
struct gg{
	int a[N];
	int cl=0;
}t[N];
int tt[N][N];
int c,n,m,d,q,k,w[N];
long long ans;
long long s[N];
int vl[N];
queue <int> ql;
int ss(int x,int y){
	memset(s,0x7f,sizeof(s));
	memset(vl,0,sizeof(vl));
	s[x]=0;
	vl[x]=1;
	ql.push(x);	
	while(!ql.empty()){
		int u=ql.front();
		ql.pop();
		vl[u]=0;
		for(int i=1;i<=t[u].cl;i++){
			int v=t[u].a[i];
			if(s[v]>s[u]+tt[u][v]){
				s[v]=s[u]+tt[u][v];if(!vl[v]){
				vl[v]=1;
				ql.push(v);
			}
			}
			
		}
	}
	return s[y];
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int x,y;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			t[i+m].a[++t[i+m].cl]=x;t[x].a[++t[x].cl]=i+m;
			tt[i+m][x]=y;tt[x][i+m]=y;
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int aa=ss(x,y);
		long long ans=aa+w[x]+w[y];
		cout<<ans<<'\n';
	}
	return 0;
}

