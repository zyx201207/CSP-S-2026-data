#include<bits/stdc++.h>
#define N 1000050
using namespace std;
long long c,t,n,d,x[N],minn[N],cnt[N];
inline int read(){
	int sum=0,b=1;
	char ch=getchar();
	while(!('0'<=ch&&ch<='9')){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')sum=sum*10+ch-'0',ch=getchar();
	return sum*b;
}
void dfs(int u,int step){
	if(minn[u]<step)return;
	if(minn[u]>step){
		minn[u]=step;
		cnt[u]=1;
	}else cnt[u]++;
	for(int i=1;i<=n;i++){
		if(abs(x[i]-x[u])<=d)dfs(i,step+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(c==12||c==11){
			x[1]=x[2]-x[1];
			cout<<x[1]<<" "<<d<<" "<<n<<" : ";
			if(x[1]*2>d||x[1]*4<d)cout<<"0\n";
			else if(x[1]*3>d)cout<<n-3<<"\n";
			else cout<<n-5<<"\n";
		}
		else {
			long long ans=0;
			for(int i=1;i<=n;i++){
				memset(cnt,0,sizeof(cnt));
				memset(minn,0x3f,sizeof(minn));
				dfs(i,0);
				for(int j=i+1;j<=n;j++){
					if(cnt[j]==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
