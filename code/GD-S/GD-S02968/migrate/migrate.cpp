#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define ciallo continue
using namespace std;
inline int read(){
	char c=getchar();
	int res=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		res=res*10+c-48;
		c=getchar();
	}
	return res*f;
}
const int N=2e6+10;
int c,t,n,d,ans;
int x[N],a[N];
queue<PII> q;
int r[N];
inline void dfs(int start,int finish,int cnt){
	if(start==finish){
		r[cnt]++;
		return;
	}
	if(x[start]+d<x[start+1]) return;
	for(int i=start+1;i<=a[start]&&i<=finish;i++){
		dfs(i,finish,cnt+1);
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read();
		d=read();
		ans=0;
		for(int i=1;i<=n;i++){
			x[i]=read();
			while(!q.empty()&&q.front().second+d<x[i]){
				a[q.front().first]=i-1;
				q.pop();
			}
			q.push({i,x[i]});
			if(i==n){
				while(!q.empty()){
					a[q.front().first]=i;
					q.pop();
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=a[i]+1;j<=n;j++){
				memset(r,0,sizeof(r));
				dfs(i,j,0);
				int w=1;
				while(r[w]==0&&w<=j-i) w++;
				if(r[w]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
