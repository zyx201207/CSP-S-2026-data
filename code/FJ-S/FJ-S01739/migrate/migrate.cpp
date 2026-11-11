#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void dd(ll &x){
	x=0;
	char ch=getchar();int ff=1;
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0',ch=getchar();
	}
	x*=ff;
}
const int N=5005;
ll T,n,a[N],f[N],w[N],dl[N],d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	dd(T),dd(T);
	while(T--){
		dd(n),dd(d);
		int ans=0;
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int x=1;x<=n;++x){
			f[x]=0,w[x]=1;
			int r=0,l=1;dl[++r]=x;
			for(int y=x+1;y<=n;++y){
				while(a[y]-a[dl[l]]>d&&l<=r) ++l;
				if(l>r) break;
				f[y]=f[dl[l]]+1,w[y]=w[dl[l]];
				if(l+1<=r&&f[dl[l+1]]==f[dl[l]]) w[y]+=w[dl[l+1]];
				if(l+2<=r&&f[dl[l+2]]==f[dl[l]]) w[y]+=w[dl[l+2]];
				if(w[y]>2) w[y]=3;
				if(w[y]==2) ++ans;
//				cout<<l<<" "<<r<<endl;
//				cout<<x<<" "<<y<<" "<<f[y]<<" "<<w[y]<<endl; 
				while(r>=l&&f[dl[r]]>f[y]) --r;
				dl[++r]=y;
			}
		}
		printf("%d\n",ans);
	}
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
