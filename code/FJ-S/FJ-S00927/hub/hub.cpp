#include <bits/stdc++.h>
using namespace std;
template <typename type>
void read(type &val){
	val=0;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
		ch=getchar();
	while('0'<=ch&&ch<='9'){
		val=val*10+(ch-'0');
		ch=getchar();
	}
}
template <typename type>
void write(type val){
	int top=0;
	static char __dights[32];
	do{
		__dights[++top]=val%10+'0';
		val/=10;
	}while(val);
	while(top)
		putchar(__dights[top--]);
}
namespace Case1{
	const int maxN=10;
	int n,k,ans,d[maxN+5];
	bool flag[maxN+5];
	vector<int> edge[maxN+5];
	void dfs(int id){
		flag[id]=false;
		for(auto to:edge[id])
			if(flag[to]) dfs(to);
	}
	void solve(){
		ans=(1<<30);
		for(int i=1;i<=n;i++)
			edge[i].clear();
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for(int tar=0;tar<(1<<n);tar++){
			if(__builtin_popcount(tar)!=k)
				continue;
			fill(flag+1,flag+n+1,false);
			for(int i=1;i<=n;i++)
				if(tar>>(i-1)&1)
					flag[i]=true;
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(flag[i])
					dfs(i),cnt++;
			if(cnt>2)
				continue;
			queue<int> que;
			fill(d+1,d+n+1,(1<<30));
			for(int i=1;i<=n;i++)
				if(tar>>(i-1)&1)
					d[i]=0,que.push(i);
			int now=0;
			while(!que.empty()){
				int id=que.front();
				que.pop();
				now=max(now,d[id]);
				for(auto to:edge[id]){
					if(d[to]==(1<<30)){
						que.push(to);
						d[to]=d[id]+1;
					}
				}
			}
			ans=min(ans,now);
		}
		printf("%d\n",ans);
	}
	void _main(){
		int T;
		read(T);
		for(;T;T--) solve();
	} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int index;
	read(index);
//	if(index<=3)
		Case1::_main(); 
}

