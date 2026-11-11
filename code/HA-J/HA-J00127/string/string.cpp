#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
char c[N];
long long a[N],ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;i++)
	{
		while(a[i]>=a[j]&&i<j)
		{
			if(c[i]!=c[j])
				ans+=a[j];
			a[i]-=a[j];
			j--;
		}
		if(c[i]!=c[j])
			ans+=a[i];
		a[j]-=a[i];
	}
	cout<<ans;
	return 0;
}
