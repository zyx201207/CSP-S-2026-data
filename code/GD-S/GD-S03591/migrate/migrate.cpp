#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define ll long long 
char Begin;
using namespace std;
ll read(){
	ll num=0,f=1;
	char ch;ch=getchar();
	while((ch<48||ch>57)&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch>47&&ch<58){
		num=(num<<1)+(num<<3)+(ch^48);
		ch=getchar();
	}return num*f;
}
const int N=2e6+15;
int tid,n;
ll a[N],m;
int p[N],q[N];
ll ans;
int f[N],g[N];
bool chk1(){
	int u=n,v=n-1;
	while(u&&p[u]==n)u--;
	while(u&&p[u]==v)u--,v--;
	return u==0;
}
bool chk2(){
	fr(i,1,n)if(p[i]==n&&q[i]==1)return 1;
	return 0;
}
int tt;
char End;
void work(){
	n=read(),m=read(),ans=0;
	fr(i,1,n)a[i]=read();
	for(int i=n,j=n;i>=1;i--){
		while(a[j]-a[i]>m)j--;
		p[i]=j;
	}
	for(int i=1,j=1;i<=n;i++){
		while(a[i]-a[j]>m)j++;
		q[i]=j;
	}
	tt++;
	if(chk1()){
		if(p[1]-1<2){puts("0");return;}
		printf("%d\n",max(n-p[1]*2+3,0));
		return;
	}
	if(chk2()){
		if(p[1]==q[n]){
			fr(i,1,p[1]-1)if(p[i]==p[1]&&p[1]-2>0)ans+=p[p[1]-1]-p[p[1]-2];
			fr(i,1,p[1]-1)if(p[i]==p[1]+1&&p[1]+2<=n)ans+=n-p[p[1]-1];
		}
		if(p[1]==q[n]+1){
			fr(i,1,p[1]-2)if(p[i]==p[1])ans+=n-p[p[1]-2];
		}
		printf("%lld\n",ans);
		return;
	}
	fr(i,1,n){
		f[i]=0,g[i]=1;
		bool bz=0;
		for(int j=i+1,k=i;j<=n;j++){
			if(a[j]-a[j-1]>m)break;
			while(a[j]-a[k]>m)k++;
			f[j]=f[k]+1;
			g[j]=g[k]+(k+1<j&&f[k+1]==f[k])*g[k+1];
			g[j]+=(k+2<j&&f[k+2]==f[k])*g[k+2];
			if(g[j]>2)g[j]=3;
			if(g[j]==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	cerr<<(&End-&Begin)/1024/1024<<endl;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	tid=read();int Q=read();
	while(Q--)work();
}