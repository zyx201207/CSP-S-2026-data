#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n;
int a[maxn];
char c[maxn];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r)
	{
		int num=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=num*1LL;
		a[l]-=num,a[r]-=num;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<ans<<endl;
	return 0;
}
