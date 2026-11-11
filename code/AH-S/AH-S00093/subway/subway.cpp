#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int M=5e5+10;
int w[M];
int k[N],a[N][N],t[N][N];
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a[i][j]=read();
			t[i][j]=read();
		}
	}
	int Q=read();
	while(Q--){
		int cur=0;
		int x=read(),y=read();
		int ans=w[x];
		cur=x;
		int lst=0;
		if(c>=7&&c<=11){
			while(cur!=y){
				ans+=t[lst][cur];
				lst=cur;
				//cur=a[cur][]
			}
		}
		if(c>=12&&c<=19){
		
		}
		cout<<0<<endl;
	}
	
	return 0;
}
