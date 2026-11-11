#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2000005;
int c,t,n,d,a[N],f[N],g[N],sg[N],ans;
inline void pre(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i],f[i]=g[i]=sg[i]=0;
}
inline void subsolve(int l,int r){
	for(int i=l;i<=r;i++){
		f[i]=0;
		g[i]=sg[i]=1;
		sg[i-1]=0;
		int p=i,q=i+1;
		for(int j=i+1;j<=r;j++){
			while(p<j&&a[j]-a[p]>d)++p;
			f[j]=f[p]+1;
			q=max(q,p);
			while(q<j&&f[q]==f[p])++q;
			g[j]=min(3ll,sg[q-1]-sg[p-1]);
			sg[j]=sg[j-1]+g[j];
			if(g[j]==2)++ans;
		}
	}
}
inline void solve(){
	pre();
	int pre=1;
	for(int i=2;i<=n+1;i++){
		if(i==n+1||a[i]-a[i-1]>d){
			subsolve(pre,i-1);
			pre=i;
		}
	}
	cout<<ans<<'\n';
}
inline void solve2(){
	pre();
	if(n==1){
		cout<<"0\n";
		return;
	}
	int g=d/(a[2]-a[1]);
	if(g<=1){
		cout<<"0\n";
		return;
	}
	int w=g+g-1;
	if(w>n-1){
		cout<<"0\n";
		return;
	}
	cout<<n-w<<'\n';
}
inline void solve3(){
	pre();
	if(n<=2){
		cout<<"0\n";
		return;
	}
	int r=0;
	for(int i=1;i<=n;i++){
		int p=lower_bound(a+1,a+n+1,a[i]-d)-a;
		if(p+1>=i)continue;
		int q=lower_bound(a+1,a+n+1,a[p+2]-d)-a-1;
		int s=lower_bound(a+1,a+n+1,a[p+1]-d)-a-1;
		r+=q;
		r-=s;
	}
	cout<<r<<'\n';
}
signed main(){
#ifndef XYZ
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--)solve();
	}else if(c>=11&&c<=12){
		while(t--)solve2();
	}else if(c>=13&&c<=14){
		while(t--)solve3();
	}
	return 0;
}

