#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=0x3f3f3f3f;
int read(){
	char ch=getchar();
	int x=0,y=1,cnt=5;
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'&&cnt){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*y;
}
int c,T,n,d,a[N],dis[N],num[N],ans;
bool f;
void dfs(int x,int step){
	for(int i=x+1;i<=n;i++){
		if(a[i]-a[x]<=d){
			if(step+1<dis[i]){
				dis[i]=step+1;
				num[i]=1;
			}else if(step+1==dis[i]){
				num[i]++;
			}
			dfs(i,step+1);	
		}else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		f=1,ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			dis[i]=INF;
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=0;
		}
		if(f){
			printf("%d\n",max(0,n-2*d+1));
		}else if(n<=300){
			for(int i=1;i<=n;i++){
				dfs(i,0);
				for(int j=i+1;j<=n;j++){
					if(num[j]==2) ans++;
					dis[j]=INF,num[j]=0;
				}
			}
			printf("%d\n",ans);
		}else puts("0");
	}
	return 0;
}
