#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,ans,cnt2=1;
struct node
{
	int l,r,w;
}k[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin>>a>>b;
		k[i-1].l=cnt2,k[i-1].r=cnt2+a-1;
		cnt2+=a;
		k[i-1].w=b-'a';
	}
	cnt2--;
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		if(cnt<=i) break;
		int revl=cnt2-k[i-1].r+1;
		int revr=cnt2-k[i-1].l+1;
		int mxr,mxl;
		mxr=k[cnt-1].r;
		while(cnt>i)
		{
			mxl=k[cnt-1].l;
			if(k[i-1].w!=k[cnt-1].w) ans+=max(0ll,min(revr,k[cnt-1].r)-max(revl,k[cnt-1].l)+1);
			if(mxr>=revr && mxl<=revl) break;
			cnt--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
