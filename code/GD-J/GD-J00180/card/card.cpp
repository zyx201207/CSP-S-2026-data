#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int read() {
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int maxn=5e5+5;

int n,m,a[maxn];
int ans[maxn];

bool vis[maxn];

signed main() {

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	n=read(),m=read();
	
	for(int i=1;i<=n;i++) a[i]=read();
	
	for(int i=1;i<=n;i++) {
		
		memset(vis,false,sizeof(vis));
		deque<int> q;
		
		for(int j=i;j<=n;j++) {
			
			if(!vis[a[j]]) q.push_back(a[j]),vis[a[j]]=true;
			else {
				
				while(!q.empty()&&q.back()!=a[j]) vis[q.back()]=false,q.pop_back();
			}
		}
		
		while(!q.empty()) 
			ans[q.front()]++,q.pop_front();
	}
	
	for(int i=1;i<=m;i++)
		write(ans[i]),putchar(' ');

	return 0;
}
