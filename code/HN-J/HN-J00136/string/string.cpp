#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+10,maxl=1e3+10; 
int n;
int ans=0;
int a[N],b[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1,op;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		b[i]=(c-'a');
	}
	int l=1,r=n;
	while(l<r)
	{
		if(b[l]!=b[r]) ans+=min(a[l],a[r]);
		if(a[l]<a[r]) a[r]-=a[l++];
		else a[l]-=a[r--];
	}
	cout<<ans;
	return 0;
}
