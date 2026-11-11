#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll c,t,n,d,mi,ans,Cnt,x[N];
ll read(){
	char ch;ll s=0,w=1;
	while((ch=getchar())>'9' || ch<'0') if(ch=='-') w=-1;
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs(ll u,ll v,ll D,ll cnt){
	if(Cnt>2) return ;
	if(u==v){
		if(cnt<mi){
			mi=cnt;
			Cnt=1;
		}
		else if(cnt==mi){
			Cnt++;
		}
		return ;
	}
	if(x[u+1]-x[u]>d){
		Cnt=3;
		return ;
	}
	if(D+x[u+1]-x[u]<=d){
		dfs(u+1,v,D+x[u+1]-x[u],cnt);
	}
	dfs(u+1,v,x[u+1]-x[u],cnt+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		ans=0;
		for(int i=1;i<=n;i++) x[i]=read();
		if(c==11 || c==12){
			if(d/(x[2]-x[1])<=1 || n-d/(x[2]-x[1])-1<=0) cout<<0<<"\n";
			else cout<<2*(n+1-d/(x[2]-x[1]))-1-n<<"\n";
			continue;
		}
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				mi=n;
				Cnt=0;
				dfs(u,v,0,1);
				if(Cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
