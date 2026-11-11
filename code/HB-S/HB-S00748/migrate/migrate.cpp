#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int w = 1,s = 0;
	char ch = getchar();
	while(ch<48||ch>57){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch>=48&&ch<=57){
		s = (s<<1)+(s<<3)+(ch^48);
		ch = getchar();
	}
	return w*s;
}

const int N = 2e6+10;

int c,T;
int n,d,x[N],f[N],cnt,h;

void dfs(int now,int goal,int step,int g){
	if(now>goal||step>g)return;
	if(now==goal&&step==g){
		h++;
		return;
	}
	for(int i = now+1;i <= f[now];++i){
		dfs(i,goal,step+1,g);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),T = read();
	while(T--){
		cnt = 0;
		n = read(),d = read();
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;++i)x[i] = read();
		for(int i = 1;i <= n;++i){
			f[i] = i;
			for(int j = i+1;j <= n;++j){
				if(x[j]-x[i]>d)break;
				f[i] = j;
			}
		}
		f[n] = n;
		for(int i = 1;i <= n;++i){
			for(int j = i+1;j <= n;++j){
				int a = i,step = 0;
				h = 0;
				while(true){
					if(a>=j||f[a]==a)break;
					step++;
					a = f[a];
				}
				dfs(i,j,0,step);
				if(h==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}