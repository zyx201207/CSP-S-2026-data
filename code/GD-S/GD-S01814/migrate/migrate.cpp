#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define int long long
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0)return;
	write(x/10);
	putchar(x%10+'0');
}
int c,T;
int n,d;
int zb[2000006];
int f[5005][5005];
void migrate(){
	memset(f,0,sizeof(f));
	n=read();d=read();
	for(int i=1;i<=n;i++){
		zb[i]=read();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(zb[i]-zb[j])<=d)f[i][j]=1;
			else{
				for(int k=i+1;k<j;k++){
					if(abs(zb[i]-zb[k])<=d&&abs(zb[j]-zb[k])<=d)
						f[i][j]+=(f[i][k]+f[k][j]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[i][j]==2){
//				cout<<"i:"<<i<<" j:"<<j<<endl;
				ans++;	
			}
		}
//		write(f[i]);
//		putchar(' ');
	}
//	putchar('\n');
	if(ans==0)putchar('0');
	else write(ans);
	putchar('\n');
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--){
		migrate();
	}
	return 0;
}
