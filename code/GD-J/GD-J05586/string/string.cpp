#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2*1e5+10;
ll n,sum;
string ans;
struct sd{
	ll lg;
	char c;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].lg>>a[i].c;
		for(int j=1;j<=a[i].lg;j++)
			ans+=a[i].c;
	}
	for(int i=0,j=ans.size()-1;i<=j;i++,j--)
	{
		if(ans[i]!=ans[j])
			sum++;	
	}
	cout<<sum;
	return 0;
}
