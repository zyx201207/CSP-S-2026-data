#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[200005],b[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++) b[i]=min(a[i],a[n]-a[i]);
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=m;i++){
		int x=lower_bound(a+1,a+1+n,b[i])-a,y=lower_bound(a+1,a+1+n,a[n]-b[i]+1)-a;
		if(c[x]!=c[y]) ans+=b[i]-b[i-1];
	}
	cout<<ans;
	return 0;
}
