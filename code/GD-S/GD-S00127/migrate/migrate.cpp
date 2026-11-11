#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
#define fi first
#define se second
#define eb emplace_back
inline int read(){
	int t=1,c=getchar(),res=0;
	for(;!isdigit(c);c=getchar())if(c=='-')t=-t;
	for(;isdigit(c);c=getchar())res=(res<<1)+(res<<3),res+=c^48;
	return res*t;
}
inline void write(int num){
	if(num<0)putchar('-'),num=-num;
	if(num>9)write(num/10);
	putchar('0'+num%10);
	return;
}
const int N=1e6;
int c,t,n,d;
int x[N+7];
int pre[N+7],nxt[N+7];
int dpx[N+7];
int dpy[N+7];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		if(n==1){
			write(0),putchar('\n');
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			x[i]=read();
			dpx[i]=dpy[i]=0;
		}
		if(c==11||c==12){
			int dx=x[2]-x[1];
			d/=dx;
			n=n-2*d+1;
			write(max(0ll,n)),putchar('\n');
			continue;
		}
		if(c==13||c==14){
			int md=0;
			for(int i=1;i<=n;i++){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d)md=i;
			}
			for(int i=md;i<n;i++)x[i]=x[i+1];
			n--;
			for(int l=1,r=1;l<=n;l++,r=max(r,l)){
				while(r+1<=n&&x[r+1]-x[l]<=d)r++;
				nxt[l]=r;
				if(l!=r)dpx[r]++;
			}
			for(int l=n,r=n;r;r--,l=min(l,r)){
				while(l-1>0&&x[r]-x[l-1]<=d)l--;
				pre[r]=l;
				if(l!=r)dpy[l]++;
			}
			for(int i=1;i<=n;i++){
				if(pre[i]==i)continue;
				if(nxt[pre[i]]!=i)continue;
				dpx[i]+=dpx[pre[i]];
			}
			for(int i=n;i;i--){
				if(nxt[i]==i)continue;
				if(pre[nxt[i]]!=i)continue;
				dpy[i]+=dpy[nxt[i]];
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=dpx[i]*dpy[i];
			}
			write(ans),putchar('\n');
			continue;
		}
		for(int l=1,r=1;l<=n;l++,r=max(r,l)){
			while(r+1<=n&&x[r+1]-x[l]<=d)r++;
			nxt[l]=r;
			if(l!=r)dpx[r]++;
		}
		for(int l=n,r=n;r;r--,l=min(l,r)){
			while(l-1>0&&x[r]-x[l-1]<=d)l--;
			pre[r]=l;
			if(l!=r)dpy[l]++;
		}
		for(int i=1;i<=n;i++){
			if(pre[i]==i)continue;
			if(nxt[pre[i]]!=i)continue;
			dpx[i]+=dpx[pre[i]];
		}
		for(int i=n;i;i--){
			if(nxt[i]==i)continue;
			if(pre[nxt[i]]!=i)continue;
			dpy[i]+=dpy[nxt[i]];
		}
		for(int i=1;i<=n;i++){
			int j=nxt[i];
			if(j==i)continue;
			int k=j-1;
			if(k==i)continue;
			int l=nxt[k];
			if(l==j||l==k)continue;
			if(pre[j]!=i)continue;
			if(pre[l]!=k)continue;
			ans+=(dpx[j])*(dpy[k]);
		}
		write(ans),putchar('\n');
	}
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
*/

