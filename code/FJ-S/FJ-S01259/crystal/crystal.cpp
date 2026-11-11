#include<bits/stdc++.h>
#define int long long
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3f
#else 
#define inf 0x3f3f3f3f
#endif
#define ulp(i,a,b) for(int i=a;i<=b;++i)
#define dlp(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
inline int read(){
	char c=getchar();
	bool f=false;
	int num=0;
	while(!isdigit(c)){
		if(c=='-')f=true;
		c=getchar();
	}
	while(isdigit(c)){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar(); 
	}
	return f?-num:num;
}
void write(int x,char ed=' '){
	if(x<0)putchar('-'),x=-x;
	int stk[65],top=0;
	do{
		stk[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(stk[top--]+'0');
	putchar(ed);
}
#define N 500005
int n,m;
int a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	ulp(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	ulp(i,1,n)pre[i]=pre[i-1]+a[i];
	int ans=0;
	ulp(i,1,n){
		int l=1,r=i,res=i; 
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m)res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	write(ans,'\n');
	return 0;
}
