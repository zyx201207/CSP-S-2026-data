#include<bits/stdc++.h>
#define int long long
#define max(xxg,wj) xxg>wj?xxg:wj
#define min(xxg,wj) xxg<wj?xxg:wj
#ifdef __unix
#define getchar getchar_unlocked
#define putchar putchat_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
void write(int x){
	if(x==0) putchar('0');
	else{
		int pos=0;char stk[30]={0};
		while(x) stk[pos++]=x%10+'0',x/=10;
		while(pos--) putchar(stk[pos]);
	}
}
const int N=5e5+10;
int n,m,ans,a[N],f[N],t,k;
int find(int x,int n,int cnt){
	int res=0;
	for(int i=n;i>=1;i--)
		if(cnt+x-a[i]<=m) res++,cnt+=x-a[i]; 
		else{
			t=i,k-=cnt;
			break;
		}
	return res; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();k=m;
	int minn=LLONG_MAX,maxx=LLONG_MIN;
	for(int i=1;i<=n;i++){
		a[i]=read();
		minn=min(a[i]-a[i-1],minn),
		maxx=max(a[i]-a[i-1],maxx);
	}
	sort(a+1,a+n+1);
	if(minn!=maxx){
		f[n]=find(a[n],n,0ll);
		for(int i=n-1;i>=1;i--){
			int j=0,d=i;
			while(a[i]==a[i+1]) f[d]++,j++,i--;
			if(ans>=i) break;
			if(f[i+j]){
				k+=(a[i+j]-a[i])*(i-t);
				f[i]=find(a[i],t,k)+f[i+j]-1; 
			}else f[i]=find(a[i],i,0ll);
			ans=max(ans,f[i]);
		}write(ans);
	}else{
		int d=a[2]-a[1];
		int cnt=0,i=1;
		while(cnt+d*i<=m){
			cnt+=d*i;
			i++,ans++;
		}write(ans);
	}
	return 0;
}

