#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<j)
	{
		int minn=min(a[i],a[j]);
		if(c[i]!=c[j]) ans+=minn;
		a[i]-=minn,a[j]-=minn;
		if(!a[i]) i++;
		if(!a[j]) j--;
	}
	cout<<ans;
	return 0;
}
