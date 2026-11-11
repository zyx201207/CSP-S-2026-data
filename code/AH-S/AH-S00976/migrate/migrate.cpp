#include<cstdio>
#include<algorithm>
#include <climits>
using namespace std;
#define f(x,y,z) for(int x=y;x<=z;x++)
#define g(x,y,z) for(int x=y;x>=z;x--)
#define int long long
#define N 100005
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
int c,t,n,d,a[N];
ll s[N];
int ans1=0,ans2=0;
void dfs(int x,int cnt,int t){
	if(x==t){
		if(cnt==ans1)ans2++;
		if(cnt<ans1)ans2=1,ans1=cnt;
		return;
	}
	for(int i=x+1;i<=t;i++){
		if(a[i]-a[x]>d)break;
		dfs(i,cnt+1,t);
	}
}
void cl(){
	n=read(),d=read();
	f(i,1,n)a[i]=read();
	int ans=0;
	f(i,1,n)
		f(j,i+1,n){
			ans1=INT_MAX,ans2=0;
			dfs(i,0,j);
			if(ans2==2)ans++;
		}
	printf("%lld\n",ans);
}
main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)cl();
	return 0;
}