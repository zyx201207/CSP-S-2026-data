#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500005],a[500005],t,ans[500005],f[500005],s[500005],fa[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i)cin>>a[i];
	for(int i=n; i>=1; --i) {
		c[i]=a[n-i+1];
//		cout<<c[i]<<' ';
	}
//	cout<<'\n';
	for(int i=1; i<=n; ++i) {
		a[i]=c[i];
		c[i]=0;
//		s[i]=1;
//		cout<<a[i]<<' ';
	}
//	cout<<'\n';
	for(int i=1; i<=n; ++i) {
		if(c[a[i]])f[i]=c[a[i]];
		else c[a[i]]=i,f[i]=i;
//		cout<<f[i]<<' ';
	}
//	cout<<'\n';
	for(int i=1; i<=n; ++i) {
		if(f[i]==i) {
			fa[i]=f[i-1];
		} else fa[i]=fa[f[i]];
		s[i]=1;
		if(f[i]!=i)s[f[i]]+=s[i],s[i]=0;
//		cout<<fa[i]<<' ';
	}
//	cout<<'\n';
//	for(int i=1;i<=n;++i)cout<<s[i]<<' ';
//	cout<<'\n';
	for(int i=n; i>=1; --i) {
		if(f[i]==i) {
			s[fa[i]]+=s[i];
		}

	}
//	for(int i=1;i<=n;++i)cout<<s[i]<<' ';
//	cout<<'\n';
	for(int i=1; i<=n; ++i) {
		if(f[i]==i)ans[a[i]]=s[i];
	}
	for(int i=1; i<=m; ++i) {
		cout<<ans[i]<<' ';
	}
}














//void dfs(int l,int r){
////	cout<<l<<' '<<r<<' '<<a[l]<<'\n';
//	if(l==r){
//		ans[a[l]]++;
//		return;
//	}
//	ans[a[l]]+=r-l+1;
//	for(int i=l+1;i<=r;++i){
//		if(a[i]==a[l]){
//			dfs(l+1,i-1);
//			l=i;
//		}
//	}
//	if(l!=r)
//	dfs(l+1,r);
//}
//int main(){
////	freopen("card.in","r",stdin);
////	freopen("card.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;++i)cin>>a[i];
//	for(int i=n;i>=1;--i){
//		c[i]=a[n-i+1];
//	}for(int i=n;i>=1;--i){
//		a[i]=c[i];
//		c[i]=0;
////		cout<<a[i]<<' ';
//	}
////	cout<<'\n';
//	dfs(1,n);
//	for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
//}
//10 3 0 3
