#include<bits/stdc++.h>
using namespace std;
char ch[1<<20],*P,*Q;
#define gc() (((P==Q&&(P=(Q=ch)+fread(ch,1,1<<20,stdin))),P==Q)?EOF:*Q++)
#define int long long
inline int read(){
	int res=0;bool sign=false;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') sign=true;
	for(;isdigit(c);c=gc()) res=res*10+c-'0';
	return sign?-res:res;
}
int n,m,a[500005],ans,l,need;
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	l=1,need=0;
	for(int r=1;r<=n;r++){
		if(r!=1) need+=(r-l)*(a[r]-a[r-1]);
		while(need>m)
			need-=a[r]-a[l++];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0; 
}
