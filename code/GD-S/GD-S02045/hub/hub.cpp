#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=1e3+10;
const int inf=1e9;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
inline void print(int x){
	if(x<10){putchar(x+'0');return;}
	print(x/10);putchar(x%10+'0');
}
int n,k,dis[maxn][maxn];
void solve(){
	memset(dis,0x3f,sizeof(dis));
	n=read(),k=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		dis[u][v]=1;
		dis[v][u]=1;
	}
	cout<<rand()%n+1<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c=read(),t=read();
	while(t--){
		solve();
	}
	return 0;
}
