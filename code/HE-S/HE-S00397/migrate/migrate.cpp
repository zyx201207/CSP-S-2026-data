#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,d,n,a[N],minn,minnnum,ans;
int read(){
	char c=getchar();int op=1,r=0;
	while(c<'0'||c>'9'){if(c=='-')op*=-1;c=getchar();}
	while('0'<=c&&c<='9'){r*=10;r+=c-'0';c=getchar();}
	return r*op;
}
void dfs(int x,int v,int step){
	if(x==v){
		if(step<minn)minn=step,minnnum=1;
		else minnnum++;
		return;
	}
	for(int i=x+1;i<=v;i++){
		if(a[i]-a[x]>d)return;
		dfs(i,v,step+1);
	}
} 
void solve1(){
	ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=1e18;
				minnnum=1;
				dfs(i,j,0);
				if(minnnum==2){
					ans++;
				}
				else if(minnnum>2)break;
			}
		}
		cout<<ans<<"\n";
}
inline void solve2(){
	int d1=a[2]-a[1];
	if(d/d1<=1)cout<<0<<"\n";
	else cout<<max(n-(d/d1)-(d/d1)+1,1ll*0)<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(c<=2)solve1();
		else if(c==11||c==12)solve2();
	}
	return 0;
}
