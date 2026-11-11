#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=5e5+5;
constexpr int M=3e5+5;
int n,m,a[N],cnt[M],s[N];
bool vis[M];
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
inline void write(int x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main(){
//	freopen("card5.in","r",stdin);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int co=0;
	for(int b=1;b<=n;b++){
		co=0;
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		for(int i=b;i<=n;i++){
			if(vis[a[i]]){
				for(int j=co;j>=1;j--){
					if(s[j]==a[i]){
						co=j;
						break;
					}
					vis[s[j]]=0;
				}
			}else{
				vis[a[i]]=1;
				s[++co]=a[i];
			}
		}
		for(int i=1;i<=co;i++){
			cnt[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		write(cnt[i]);
		printf(" ");
	}
	return 0;
}

