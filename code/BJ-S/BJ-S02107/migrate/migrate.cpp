#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=2e6+10;
int n,to[maxn];
ll d,x[maxn],f[maxn],g[maxn],s[maxn];
bool vis[maxn];
int q[maxn];
inline void sol1(){
	int l=1,r=0,it=1,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[j]=n+1,g[j]=0,s[j]=0;
		l=1,r=0,it=1;
		f[i]=0,g[i]=1,s[l]=1;
		q[++r]=i;
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[j-1]>d) break;
			while(l<=r&&x[j]-x[q[l]]>d) l++;
			if(l>it){
				it=l;
				while(it<r&&f[q[it+1]]==f[q[l]]) it++;
			}
			f[j]=f[q[l]]+1;
			g[j]=s[it]-s[l-1];
			while(l<=r&&f[q[r]]>f[j]) r--;
			q[++r]=j;
			s[r]=s[r-1]+g[j];
		}
	//	cout<<i<<endl;
	//	for(int j=i;j<=n;j++) cout<<f[j]<<' ';cout<<endl;
	//	for(int j=i;j<=n;j++) cout<<g[j]<<' ';cout<<endl;
		for(int j=i;j<=n;j++)
			if(g[j]==2) ans++;
	}
	cout<<ans<<endl;
}
inline void sol2(){
	if(x[2]-x[1]>d) return cout<<0<<endl,void();
	int l=1,r=0,it=1,ans=0;
	for(int j=1;j<=n;j++) f[j]=n+1,g[j]=0,s[j]=0;
	l=1,r=0,it=1;
	f[1]=0,g[1]=1,s[l]=1;
	q[++r]=1;
	int mxl=n+1;
	for(int j=2;j<=n;j++){
		if(x[j]-x[j-1]>d) break;
		while(l<=r&&x[j]-x[q[l]]>d) l++;
		if(l>it){
			it=l;
			while(it<r&&f[q[it+1]]==f[q[l]]) it++;
		}
		f[j]=f[q[l]]+1;
		g[j]=s[it]-s[l-1];
		while(l<=r&&f[q[r]]>f[j]) r--;
		q[++r]=j;
		s[r]=s[r-1]+g[j];
		if(g[j]==2){mxl=j;break;}
	}
	//	cout<<i<<endl;
	cout<<n-mxl+1<<endl;
}
int c,t;
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=n,j=n;i;i--){
		while(x[j]-x[i]>d) j--;
		to[i]=j;
	}
	if(n<=5000) sol1();
	else if(c==11||c==12) sol2();
	for(int i=1;i<=n;i++) vis[i]=to[i]=f[i]=0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);//
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
