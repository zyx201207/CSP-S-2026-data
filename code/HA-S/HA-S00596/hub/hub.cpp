#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,x,y,e[N],ne[N],h[N],idx,f[N][21],dep[N],a[N],ans;
bool s[N];
vector<int> v;
void add(int a,int b){
	e[++idx]=b;
	ne[idx]=h[a];
	h[a]=idx;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i=h[x];i;i=ne[i]){
		int y=e[i];
		if(y==fa){
			continue;
		}
		f[y][0]=x;
		for(int j=1;j<21;j++){
			f[y][j]=f[f[y][j-1]][j-1];
		}
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			x=f[x][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	s[x]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=ne[i]){
			int y=e[i];
			if(!s[y]&&a[y]){
				s[y]=true;
				q.push(y);
			}
		}
	}
}
void work(int x,int y){
	if(n-x+1<y){
		return;
	}
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			s[i]=false;
		}
		for(auto i:v){
			if(!s[i]){
				cnt++;
				bfs(i);
			}
		}
		if(cnt>2){
			return;
		}
		int res=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				continue;
			}
			int min_=1e9;
			for(auto j:v){
				min_=min(min_,dep[i]+dep[j]-2*dep[lca(i,j)]);
			}
			res=max(res,min_);
		}
		ans=min(ans,res);
		return;
	}
	if(y){
		v.push_back(x);
		a[x]=true;
		work(x+1,y-1);
		v.pop_back();
		a[x]=false;
		work(x+1,y);
	}else{
		work(x+1,y);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		memset(h,0,sizeof h);
		memset(f,0,sizeof f);
		idx=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		ans=1e9;
		work(1,k);
		printf("%d\n",ans);
	}
	return 0;
}
