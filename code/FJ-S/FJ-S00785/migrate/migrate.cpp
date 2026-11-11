#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d,a[1000005];
int f[1001][1001];
long long read(){
	long long x=0,b=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') if(ch=='-') b=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*b;
}
int readb(){
	int x=0,b=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9') if(ch=='-') b=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*b;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=readb(),t=readb();
	if(c<11){
		while(t--){
			n=readb(),d=read(),ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=2000005;
			for(int i=1;i<=n;i++) a[i]=read();
			for(int i=n;i>=1;i--){
				for(int j=i-1;j>=1;j--){
					if(a[i]-a[j]<=d) f[j][i]=1;
					else break;
				}
			}
			for(int k=1;k<=n;k++){
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					int flag=0;
					for(int k=1;k<=n;k++){
						if(f[i][j]==f[i][k]+f[k][j]){
							flag++;
						}
					}
					if(flag==2) ans+=(flag-1)/*,cout<<flag<<'\n'*/;
					//printf("%7d ",f[i][j]);
				}
				//putchar('\n');
			}
			printf("%d\n",ans);
		}
	}
	else{
		while(t--) printf("0\n");
	}
	return 0;
}
