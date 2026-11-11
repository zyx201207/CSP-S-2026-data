#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[200005];
char c[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	ll ans = 0;
	int i = 0,j = n-1;
	//two-pointer
	while(i <= j)
	{
		if(c[i] != c[j]) ans += min(a[i],a[j]);
		if(a[i] > a[j]) a[i] -= a[j],a[j] = 0,j--;
		else if(a[i] < a[j]) a[j] -= a[i],a[i] = 0,i++;
		else a[i] = 0,a[j] = 0,i++,j--;
	}
	cout<<ans;
	return 0;
}
