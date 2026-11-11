#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
inline int read(){
	int f=1,g=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		g=(g<<3)+(g<<1)+(c-'0');
		c=getchar();
	}
	return f*g;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar((x%10)+'0');
	return ;
}
const int N=2e6+10;
int c,T,n,d,a[N];
void solve1(){
	if(n==1){
		cout<<"0\n";
		return ;
	}
	int g=a[2]-a[1];
	if(d<g*2){
		cout<<"0\n";
		return ;
	}
	d=d/g*2-1;
	write(max(0LL,n-d));
	putchar('\n');
	return ;
}
void solve(){
	n=read(),d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(c==11||c==12)solve1();
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate4.in","r",stdin);
//	freopen("my.out","w",stdout);
	c=read(),T=read();
	while(T--)solve();
	return 0;
}
/*
4 2
1 2 3 4

5 3
-2 -1 0 1 2
*/

