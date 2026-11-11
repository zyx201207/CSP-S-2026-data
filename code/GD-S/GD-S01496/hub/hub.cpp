#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
vector<int>e[N];
int n,k,a[N],d[N],res,ans,c,p[N];
bool v[N];
void js(int x,int f){
	if(v[x]&&!v[f]){
		c++;
	}
	d[x]=0;
	for(int y:e[x]){
		if(y==f)continue;
		js(y,x);
		if(d[y]==-1)continue;
		d[x]=max(d[x],d[y]+1);
	}
	res=max(res,d[x]);
	if(v[x]){
		d[x]=-1;
	}
}
void dfs(int x){
	if(x>k){
		c=0;
		res=0;
		js(a[1],0);
		if(c<=2){
			ans=min(ans,res);
		}
		return ;
	}
	for(int i=a[x-1]+1;i<=n;i++){
		a[x]=i;
		v[i]=1;
		dfs(x+1);
		v[i]=0;
	}
}
void solve(int x,int f){
	d[x]=0;
	p[x]=0;
	for(int y:e[x]){
		if(y==f)continue;
		solve(y,x);
		if(d[y]+1>d[x]){
			p[x]=d[x];
			d[x]=d[y]+1;
		}else if(d[y]+1>p[x]){
			p[x]=d[y]+1;
		}
	}
}
void lls(int x,int f){
	if(f!=0){
		if(d[f]+1>d[x]){
			p[x]=d[x];
			d[x]=d[f]+1;
		}else if(d[f]+1>p[x]){
			p[x]=d[f]+1;
		}
	}
	int len=max(p[x],d[x]/2);
	ans=min(ans,len);
	for(int y:e[x]){
		if(y==f)continue;
		int pp=p[x],pd=d[x];
		if(d[y]+1==d[x]){
			d[x]=p[x];
		}
		lls(y,x);
		p[x]=pp;
		d[x]=pd;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int id,t;
	cin>>id>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if(id==7||id==11||id==12){
			ans=n;
			solve(1,0);
			lls(1,0);
		}else{
			ans=n;
			dfs(1);
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}
