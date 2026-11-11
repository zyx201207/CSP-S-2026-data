#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
char c[N];
long long ans,l,r;
struct node{
	long long len;
	char c;
};
vector<node> a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x>>c[i];
		if(i!=1&&c[i]!=c[i-1])
		{
			a.push_back({r-l,c[i-1]});
			l=r;
		}
		r+=x;
	}
	if(c[n]==c[n-1]||n==1)
		a.push_back({r-l,c[n]});
	int len=0,i=0;
	while(i<a.size()/2)
	{
		if(a[i].c!=a[a.size()-i-1].c)
			ans+=max(a[i].len,a[a.size()-i-1].len);
		else
			ans+=abs(a[i].len-a[a.size()-i-1].len);
		len+=max(a[i].len,a[a.size()-i-1].len);
		i++;
	}
	cout<<ans;
}
