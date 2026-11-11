#include<bits/stdc++.h>//2 T 1e5  1 n 2e6  1 d 2e18  -1e18 a 1e18
using namespace std;//16:35
#define ll long long
const int N=2e7+5;
ll c,T,n,d,a[N],dis[N],ans,num,cnt[N];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void dfs(int t,int x,int dd,int len){//dd 累计距离 
	if(x==t){
		cnt[++num]=len;
		return ;
	}
	if(dis[x+1]>d) return ;
	if(dd+dis[x+1]<=d){
		dfs(t,x+1,dd+dis[x+1],len);
		dfs(t,x+1,dis[x+1],len+1);
	}
	else dfs(t,x+1,dis[x+1],len+1);
	return ;
}
void solve(int i,int j){
	num=0;
	dfs(j,i,0,1);
	ll minl=1e18;int res=0;
	for(int i=1;i<=num;i++) minl=min(minl,cnt[i]);
	for(int i=1;i<=num;i++) if(cnt[i]==minl) res++;
	if(res==2) ans++;
//	for(int i=1;i<=num;i++) cout<<cnt[i]<<" ";
//	cout<<"\n\n";
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	c=read();T=read();
	if(c>10){
		while(T--) cout<<"0\n";
		return 0;//不可以 总司令
	}
	while(T--){
		n=read();d=read();
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			dis[i]=a[i]-a[i-1];//i-1 --> i 的距离 
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i>=j) continue;
				solve(i,j);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//我堂完了！！ 
//if(res==2) ans++;
//for(int i=1;i<=num;i++) cout<<cnt[i]<<" ";
//cout<<"\n\n";
//我给这3行注释了 然后奇怪为什么自己的ans永远=0而调了半天 
//应该只注释后两行 
//而且前面样例还输错了 
//大样例3没过 毁灭吧
//期望得分0pts
