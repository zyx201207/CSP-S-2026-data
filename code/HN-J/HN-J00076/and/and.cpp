#include<bits/stdc++.h>
using namespace std;
#define int long long
char buf[1<<21],*p1=buf,*p2=buf;
inline char gc(){
	if(p1==p2){
		p2=(p1=buf)+fread(buf,1,1<<21,stdin);
		if(p1==p2) return EOF;
	}
	return *p1++;
}
inline int read(){
	int x=0,f=1;
    char c=gc();
    while(c<'0' || c>'9'){
    	if(c=='-') f=-1;
    	c=gc();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=gc();
	}
	return x*f;
}
const int N=2e5+10;
int n,m,cnt,x,ans,a[N]; 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read(); 
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=30;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			x=(a[j]>>i)&1;
			if(x==1) cnt++;
		}
		if(cnt>=m){
			ans|=(1<<i);
			sort(a+1,a+1+n,greater<int>());
			n=cnt;
			for(int j=1;j<=n;j++){
				x=(a[j]>>i)&1;
				if(x==1) a[j]-=(1<<i);
			}
		} 
		else
			for(int j=1;j<=n;j++){
				x=(a[j]>>i)&1;
				if(x==1) a[j]-=(1<<i);
			}
	}
	cout<<ans;
	return 0;
}
