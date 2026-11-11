#include<bits/stdc++.h>
using namespace std;
int n,r2;char sc[200010];
long long len,l,r,ans,sa[200010];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int a;
		char c;
		cin>>a>>c;
		len+=a;
			sa[i]=a,sc[i]=c;
	}
	r=len;r2=n;
	for(int i=1;i<=n;++i)
	{
		if(l>=r-1) break;
		int ri=sa[r2];
		while(sa[i]>ri)
		{
			if(sc[i]!=sc[r2]) ans+=sa[r2];
			--r2,ri+=sa[r2];
		}
		l+=sa[i];
		r-=sa[i];
		if(sc[i]!=sc[r2]) ans+=sa[r2]-(ri-sa[i]);
		if(sa[i]<ri)
		{
			sa[r2]-=sa[r2]-(ri-sa[i]);
			++r2;
		}
		--r2;
		if(l>=r-1) break;
	}
	cout<<ans;
	return 0;
}
