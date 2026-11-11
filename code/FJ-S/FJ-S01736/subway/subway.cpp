#include<bits/stdc++.h>
using namespace std;
int read(){
	int res = 0,f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9')res = res*10+(ch^48),ch = getchar();
	return res*f;
}
map<pair<int,int>,int> mp;

long long ans = 1e16;
int c,n,m,d,q,st,en;
int w[500005];
vector<int> a[505];

int t[505][500005];

int k[505];
int head[500010],nxt[500010*2],ver[500010*2],id[500010*2],tot;
bool v[500005];
void add(int x,int y,int z){
	ver[++tot] = y,id[tot] = z,nxt[tot] = head[x],head[x] = tot;
}
void dfs(int x,int lst,int T,long long cnt){
	if(x == T){
		ans = min(ans,cnt+w[T]+t[lst][mp[make_pair(lst,x)]]);
		
		return ;
	}
	v[x] = 1;
	for(int i = head[x];i;i = nxt[i]){
		int y = ver[i],now = id[i];
		if(v[y])continue;
		if(lst == now){
			dfs(y,lst,T,cnt);
		}else{
			dfs(y,now,T,cnt + t[lst][mp[make_pair(lst,x)]] + t[now][mp[make_pair(now,x)]]);
		}
	}
}
void solve(){
	int TT = t[1][0];
	int cnt = 0;
	queue<pair<int,int> > q;
	q.push(make_pair(st,0));v[st] = 1;
	while(!q.empty()){
		int x = q.front().first,from = q.front().second;q.pop();
		for(int i = head[x];i;i = nxt[i]){
			int y = ver[i];
			if(v[y])continue;
			if(from != id[i]){
				if(x == st){
					cnt++;
				}else{
					cnt += 2;
				}
			}
			q.push(make_pair(y,id[i]));
			
			if(y == en){
				cnt++;
				ans = w[st]+w[en]+cnt*TT;
				return ;
			}
		}
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c = read(),n = read(),m = read(),d = read(),q = read();
	for(int i = 1;i<=m;i++)w[i] = read();
	for(int i = 1;i<=n;i++){
		k[i] = read();
		for(int j = 1;j<=k[i];j++){
			int x,y;x = read(),y = read();
			a[i].push_back(x);t[i][j-1] = y;
			mp[make_pair(i,x)] = j-1;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<k[i];j++){
			int x = a[i][j-1],y = a[i][j];
			add(x,y,i);add(y,x,i);
		}
	}
	
	
	
	if(c>=12&&c<=19){
		//cout<<t[1][0]<<endl;
		while(q--){
			ans = 0;memset(v,0,sizeof(v));
			st = read(),en = read();
			solve();
			printf("%d\n",ans);
		}
		return 0;
	}
	
	
	while(q--){
		ans = 1e16;memset(v,0,sizeof(v));
		st = read(),en = read();
		dfs(st,0,en,w[st]);
		printf("%d\n",ans);
	}
	
	
	/*
	for(int i = 1;i<=m;i++)cout<<w[i]<<' ';
	cout<<endl;
	for(int i = 1;i<=n;i++){
		cout<<k[i]<<' ';
		for(int j = 0;j<k[i];j++)cout<<a[i][j]<<' '<<t[i][j]<<' ';
		cout<<endl;
	}
	*/
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
