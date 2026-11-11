#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,x,y,z) for(int i=x;i<=y;i+=z)
#define REP(i,x,y,z) for(int i=x;i>=y;i-=z)
void rd(int &x){
	int f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	x*=f;
}void wr(int x,char end='\n'){
	if(x<0)putchar('-'),x=-x;
	int len=0,s[20];
	if(x==0)s[++len]=0;
	while(x)s[++len]=x%10,x/=10;
	while(len)putchar(s[len--]+'0');
	putchar(end);
}const int N=2e5+10;
int n,m,a[N],ans;
inline bool check(int x){
	int cnt=0;FOR(i,1,n,1)if((a[i]&x)==x)cnt++;
	return cnt>=m;
}signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	rd(n),rd(m);FOR(i,1,n,1)rd(a[i]);
	REP(i,30,0,1){
		int j=(1ll<<i),res=ans|j;
		if(check(res))ans=res;
	}wr(ans);
	return 0;
}
