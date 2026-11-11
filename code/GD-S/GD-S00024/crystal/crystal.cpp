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
const int N=5e5+10;
int n,m,a[N],pre[N],ans;
bool chk(int j,int i){
	if((i-j+1)*a[i]-pre[i]+pre[j-1]<=m)return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,cnt=1;
//		cerr<<"@ "<<i<<'\n';
		while(l<r){
			int mid=(l+r)>>1;
//			cerr<<l<<' '<<r<<' '<<mid<<'\n';
			if(chk(mid,i))r=mid,cnt=mid;
			else l=mid+1;
//			cerr<<l<<' '<<r<<'\n'<<'\n';
		}
		ans=max(ans,(i-cnt+1));
//		cerr<<"# "<<i-cnt+1<<'\n';
	}
	write(ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
