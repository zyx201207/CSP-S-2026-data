#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j)
	{
		if(a[i]<a[j]) ans+=a[i]*(c[i]!=c[j]),a[j]-=a[i],i++;
		else if(a[i]==a[j]) ans+=a[i]*(c[i]!=c[j]),i++,j--;
		else ans+=a[j]*(c[i]!=c[j]),a[i]-=a[j],j--;
	}
	cout<<ans;
	return 0;
}

