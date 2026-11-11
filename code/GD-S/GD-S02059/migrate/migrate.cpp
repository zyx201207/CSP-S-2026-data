#include<bits/stdc++.h>
#define ll long long
#define gc getchar
#define pb push_back
using namespace std;
const int N=2e6+10;
const ll inf=1e18;
inline void re(ll &s){
	s=0;
	char a=gc();
	short f=1;
	while(!isdigit(a)){
		if(a=='-') f=-1;
		a=gc();
	}
	while(isdigit(a)){
		s=(s<<3)+(s<<1)+(a-'0');
		a=gc();
	}
	s*=f;
	return;
}
ll a[N],n,m,d,c,t,ans,cnt,kk,dis;
bool A=1,B=1,C=1;
vector<int>g[N];
//vector<pair<int,int> >di[5010][5010];
void dfs(int now,int v,ll ste){
	if(a[v]-a[now]<=d){
		if(dis==ste+1){
			kk++;
		}
		else{
			dis=ste+1;
			kk=1;
		}
		return;
	}
	for(int i=now+1;;){
		dfs(i,v,ste+1);
		i++;
		if(a[i]-a[now]>d) break;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	re(c),re(t);
	while(t--){
		cnt=1;
		ans=0;
		re(n),re(d);
		for(int i=1;i<=n;i++) re(a[i]);
		g[1].pb(1);
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]>d){
				g[++cnt].pb(i);
			}
			else g[cnt].pb(i);
		}
		for(int i=1;i<=cnt;i++){
			if(g[i].size()<4) continue;
			for(int u,j=0;j<g[i].size()-3;j++){
				u=g[i][j];
		//		cout<<"u"<<u<<endl;
				for(int v,p=j+3;p<g[i].size();p++){
					v=g[i][p];
					kk=0;
					dis=inf;
					dfs(u,v,0);
		//			cout<<u<<" "<<v<<" "<<dis<<" "<<kk<<endl;
					if(kk==2){
						ans++;	
					}
				}
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=cnt;i++) g[i].clear();
	}
	
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
