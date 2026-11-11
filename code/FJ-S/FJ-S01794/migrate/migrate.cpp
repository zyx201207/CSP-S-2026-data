#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn=2000005;
vector<ll> pos(maxn);

bool visited[maxn];
bool meeted[maxn];

struct edge{
	int id,to;
	ll dista;
} e[maxn];

int n,d,cnt;

edge rte(int id, int to, ll dista){
	edge that;
	that.id=id;
	that.to=to;
	that.dista=dista;
	return that;
}

int pathway[3];

int dfs(edge rt, int sums, int firstf, int steps){
	if (rt.to>n) return 0;
	if (steps>2){
		return 0;
	}
	bool us=rt.dista>d;
	if (us) return 0;
	sums+=rt.dista;
	steps++;
	pathway[steps]=rt.to;
	for (int i=rt.to+1;i<=n;i++){
		visited[i]=true;
		dfs(rte(rt.to,i,rt.dista),sums,firstf,steps);
		visited[i]=false;
	}
	if (rt.to-firstf<=2) return 0;
	if (meeted[pathway[2]] || pathway[2]==rt.to || pathway[2]==0) return 0;
	meeted[pathway[2]]=true;
	cnt++;
	memset(pathway,0,sizeof(pathway));
	steps=0;
	return 0;
}

int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c,t;
	cin>>c>>t;
	
	while(t-->0){
		memset(visited,0,sizeof(visited));
		
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>pos[i];
			
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				e[i].id=i;
				e[i].to=j;
				e[i].dista=abs(pos[j]-pos[i]);
				dfs(e[i],0,i,1);
			}
		}
		if (cnt%2!=0){
			cnt+=1;
		}
		cout<<cnt/2<<"\n";
	}
	return 0;
}
