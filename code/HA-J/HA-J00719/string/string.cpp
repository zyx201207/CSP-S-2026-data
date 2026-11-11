#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr<<#x<<" = "<<(x)<<"\n";
#else
#define debug(x)
#endif
#define ll long long
#define PII pair<int,int>
#define vct vector
#define pb push_back
#define int long long

#ifdef LOCAL
bool ____st;
#endif
int n,l,mid,pil,pir,pol,por,ans,L;
struct node
{
	int val;
	char ch;
}a[200010];
#ifdef LOCAL
bool ____ed;
#endif

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	cerr<<double(&____ed-&____st)/(1024*1024)<<"Mib\n";
	double ____ST=clock();
#endif
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val>>a[i].ch;
		l+=a[i].val;
	}
	pol=1,por=n;
	pil=1,pir=a[n].val;
	while(L<l/2)
	{
		int nxt=min(a[pol].val-pil+1,pir);
		if(a[pol].ch!=a[por].ch)
		{
			ans+=nxt;
		}
		pil+=nxt,pir-=nxt;
		if(pil==a[pol].val+1)
		{
			pol++;
			pil=1;
		}
		if(pir==0)
		{
			por--;
			pir=a[por].val;
		}
		L+=nxt;
	}
	cout<<ans;
#ifdef LOCAL
	double ____ED=clock();
	cerr<<'\n'<<(____ED-____ST)/CLOCKS_PER_SEC*1000<<"ms\n";
#endif
	return 0;
}
