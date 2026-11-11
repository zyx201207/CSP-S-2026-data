#include <bits/stdc++.h>
using namespace std;
#define int long long
#define OI ios::sync_with_stdio(0);cin.tie(0)
#define end '\n'
#define pii pair<int,int>

const int N=2e5+5;
int n,a[N];
char c[N];
int len,pre[N];

int ans;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

//	freopen("test2.in","r",stdin);
	
	OI;
	
	cin>>n;
	len=0;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i]>>c[i];
		
		len+=a[i];
		pre[i]=pre[i-1]+a[i];
	}
	
	ans=0;
	int l=1,r=len;
	while (l<r)
	{
		int lid=lower_bound(pre+1,pre+n+1,l)-pre;
		int rid=lower_bound(pre+1,pre+n+1,r)-pre;
		
		int llst=pre[lid]-l+1,rlst=r-pre[rid-1];
		int move=min(llst,rlst);
		if (c[lid]!=c[rid]) ans+=move;
		
		l+=move,r-=move;
	}
	
	cout<<ans<<endl;
	return 0;
}
