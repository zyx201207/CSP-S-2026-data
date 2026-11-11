#include<bits/stdc++.h>
#define int long long
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
template<typename T>void read(T &x){
	x=0;T f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while((c>='0'&&c<='9')){x=x*10+(c^48);c=getchar();}
	x*=f;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,d,a[2222222],dis,b;
void dfs(int ff,int tt,int di){
	if(ff==tt){
		if(di==dis)b++;
		else b=1,dis=min(di,dis);
		return;
	}
	for(int j=ff+1;j<=tt;j++){
		if(a[ff]+d>=a[j])dfs(j,tt,di+1);
		else break;
	}
}
void sol(){
	read(n);read(d);int ans=0;
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis=0x3f;b=0;dfs(i,j,0);
			if(b==2)ans++;
		}
	}
	write(ans);puts("");
}
signed main(){
	file("migrate")
	int c,t;read(c);read(t);
	while(t--)sol();
	return 0;
}
/*
0 8
10 3
0 3 6 7 8 9 10 13 16 19
1 1999999999999999992
0
2 3
-1 2
5 3
-3 0 2 3 4
6 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 200000000000000000 600000000000000000 1000000000000000000
4 1200000000000000000
-1000000000000000000 -600000000000000000 -200000000000000000 1000000000000000000
5 3
999999999999999994 999999999999999996 999999999999999997 999999999999999998 1000000000000000000
6 4
-3 0 1 2 3 4
*/
