#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,char> p[200020];
int a[200020],b[200020];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>p[i].first>>p[i].second;
	for(int i=1;i<=n;++i) a[i]=a[i-1]+p[i].first;
	for(int i=n;i>=1;--i) b[i]=b[i+1]+p[i].first;
	int l=1,r=n,aa=0,bb=0,ans=0;
	while(l<r)
	{
		if(p[l].second!=p[r].second) ans+=min(a[l]-aa,b[r]-bb);
		int aaa=aa,bbb=bb,ll=l,rr=r;
		aa+=min(a[ll]-aaa,b[rr]-bbb);
		if(a[l]<=aa) ++l;
		bb+=min(a[ll]-aaa,b[rr]-bbb);
		if(b[r]<=bb) --r;
	}
	cout<<ans<<'\n';
	return 0;
}
