#include<bits/stdc++.h>//clear
using namespace std;
const int N=2e6+5;
int c,t,n,f[5005][5005],cnt[5005][5005];
long long d,x[N];
long long read(){
	bool f=0;
	long long num=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return f?-num:num;
}
void print(long long x){
	if(x==0) putchar('0');
	char c[15];
	int num=0;
	while(x){
		c[++num]=x%10|48;
		x/=10;
	}
	for(int i=num;i>=1;--i) putchar(c[i]);
	puts("");
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;++i) x[i]=read();
		if(c<=10){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j) f[i][j]=1e9,cnt[i][j]=0;
			}
			for(int i=1;i<=n;++i){
				int r=i;
				while(r<=n&&x[r]-x[i]<=d) ++r;
				for(int j=i;j<r;++j) f[i][j]=f[j][i]=cnt[i][j]=cnt[j][i]=1;
			}
			for(int k=1;k<=n;++k){
				for(int i=1;i<k;++i){
					if(f[i][k]>1e8) continue;
					for(int j=k+1;j<=n;++j){
						int w=f[i][k]+f[k][j];
						if(w<f[i][j]){
							f[i][j]=w;
							cnt[i][j]=cnt[i][k]*cnt[k][j];
						}
						else if(w==f[i][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
						if(cnt[i][j]>3) cnt[i][j]=3;
					} 
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(cnt[i][j]==2) ++ans;
				}
			}
			print(ans);
		}
		if(c>=11&&c<=12){
			if(n==1||x[2]-x[1]>d){
				print(0);
				continue;
			}
			long long k=d/(x[2]-x[1]);
			if(k==1){
				print(0);
				continue;
			}
			print(max(0ll,n-2*k+1));
		}
	}
	return 0;
}
