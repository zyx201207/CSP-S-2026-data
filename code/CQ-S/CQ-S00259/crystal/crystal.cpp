#include<bits/stdc++.h>
#define ll long long
#define LL long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define ld long double
#define memcsh(a) memset(a,0,sizeof(a))
#define membig(a) memset(a,0x3f,sizeof(a))
#define memsma(a) memset(a,0xC1,sizeof(a))
#define sz(v) (int)v.size()
#define MX 0x3f3f3f3f
#define MN 0xC1C1C1C1
#define MXll 0x3f3f3f3f3f3f3f3f
#define MNll 0xC1C1C1C1C1C1C1C1
#define all(v) v.begin(),v.end()
using namespace std;
const int N=5e5+5,mod=1e9+7;
bool start_MLE;
char sr[1<<21],sc[1<<21],*rx=sr,*ry=sr,*cx=sc,*cy=sc+(1<<21);
#define getc() (rx==ry&&(ry=(rx=sr)+fread(sr,1,sizeof(sr),stdin)),rx==ry?EOF:*rx++)
LL read(){
	LL x=0;
	ll y=1,c=getc();
	for(;!isdigit(c);c=getc())if(c=='-')y=-1;
	for(;isdigit(c);c=getc())x=(x<<3)+(x<<1)+(c^48);
	return x*y;
}
#define putc(c) (cx==cy&&(fwrite(sc,1,sizeof(sc),stdout),cx=sc),*cx++=c)
void write(LL x){
	if(x<0)putc('-'),x=-x;
	if(x>9)write(x/10);
	putc(x%10^48);
	return;
}
struct code_end{
	~code_end(){
		fwrite(sc,1,cx-sc,stdout);
	}
}codend;
ll n,m,a[N];
bool end_MLE;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	ll l=n,mx=0;
	per(i,n,1){
		while(l&&a[i]-a[l]<=m)m-=a[i]-a[l],--l;
		mx=max(mx,i-l);
		m+=(i-l-1)*(a[i]-a[i-1]);
	}
	write(mx);
	return 0;
}

