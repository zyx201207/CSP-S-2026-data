#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
int n,m,a[500010],s[500010],c[500010],ans,cnt;
int K(int l,int r,int*s){return l<=r?s[r]-s[l-1]:0;}
signed main(){
	fre("crystal");
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);vector<int>v(a,a+n+1);v[0]=-1e13;
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)cnt+=a[i]!=a[i-1],s[cnt]+=a[i],++c[cnt];
	for(int i=1;i<=cnt;++i)s[i]+=s[i-1],c[i]+=c[i-1];
	int j=1;
	for(int i=1;i<v.size();++i){
		while(K(j,i,c)*v[i]-K(j,i,s)>m)++j;
		ans=max(ans,min((m-K(j,i,c)*v[i]+K(j,i,s))/(v[i]-v[j-1]),K(j-1,j-1,c))+K(j,i,c));
	}
	cout<<ans;
	return 0;
}//14:53