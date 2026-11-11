#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int c,_;
int n,d;
int di[N];
int num[N][N];
int dis[N][N];
//Çó×î¶Ì¾àÀë 
void dfs1(int st,int x,int pre,int cnt){
	dis[st][x]=min(dis[st][x],cnt);
	if(x==n) return;
	int len;
	for(int i=x+1;i<=n;i++){
		len=di[i]-di[pre];
		if(len>d){
			break;
		}
		dfs1(st,i,x,cnt+1);
	}
	return;
}
void init(){
	memset(dis,0x3f,sizeof(dis));
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=n;i++)
		dfs1(i,i,i-1,0);
	/*
	cout<<"dis\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",dis[i][j]);
		}
		cout<<endl;
	}
	*/
	return;
}
void dfs2(int st,int x,int pre,int cnt){
	if(x==4&&pre==2)
		//printf("aaa %d %d %d %d\n",st,x,pre,cnt);
	if(cnt==dis[st][x]) num[st][x]++;
	if(x==n) return;
	int len;
	for(int i=x+1;i<=n;i++){
		
		len=di[i]-di[pre];
		if(i==4&&pre==2)
			//printf("bbb %d %d %d %d %d\n",st,i,pre,cnt,len);
		if(len>d) break;
		dfs2(st,i,x,cnt+1);
	}
	return;
}
void solve(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		dfs2(i,i,i,0);
		for(int j=1;j<=n;j++){
			if(num[i][j]==2) cnt++;
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",num[i][j]);
		}
		cout<<endl;
	}
	*/
	printf("%d\n",cnt);
	
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();_=read();
	while(_--){
		n=read();d=read();
		for(int i=1;i<=n;i++) di[i]=read();
		init();
		solve();
	}
	return 0;
}
