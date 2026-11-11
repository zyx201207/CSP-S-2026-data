#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked

inline int read(){
	int x=0,v=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')v=-1;
		ch=gc();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=gc();
	}
	return x*v;
}

const int N=2*1e6+5;
int c,t;
int n,d;
int x[N];
int path[N],ans[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		
		int cnt=0;
		for(int i=1;i<=n;i++){
			memset(path,0x3f,sizeof(path));
			memset(ans,0,sizeof(ans));
			queue <int> q;
			q.push(i);
			path[i]=0;
			while(!q.empty()){
				int now=q.front();q.pop();
				for(int j=now+1;j<=n;j++){
					if(x[j]-x[now]>d)break;
					if(path[j]>path[now]+1){
						path[j]=path[now]+1;
						ans[j]=1;
						q.push(j);
					}
					else if(path[j]==path[now]+1)ans[j]++;
				}
			}
			for(int i=1;i<=n;i++){
				if(ans[i]==2)cnt++;
			}
		}
		
		cout<<cnt<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
