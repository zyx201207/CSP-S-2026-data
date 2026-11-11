#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e3+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int c,t,n,d,x[N],f[N][N],cnt[N][N],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		memset(f,0x3f,sizeof f);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)x[i]=read();
		for(int i=1;i<=n;i++){
			f[i][i]=0;
			for(int j=1;j<i;j++)if(x[i]-x[j]<=d)f[j][i]=1,cnt[i][j]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<k;i++){
				if(x[i]-x[k]>d)continue;
				for(int j=k+1;j<=n;j++){
					if(x[j]-x[k]>d)continue;
					int t=f[i][k]+f[k][j];
					if(f[i][j]==t)cnt[i][j]++;
					else if(f[i][j]>t)f[i][j]=t,cnt[i][j]=1;
					//cout<<i<<"->"<<k<<"->"<<j<<" "<<f[i][j]<<" "<<cnt[i][j]<<"\n";
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					//cout<<i<<" "<<j<<"\n";
					ans++;
				}
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}
