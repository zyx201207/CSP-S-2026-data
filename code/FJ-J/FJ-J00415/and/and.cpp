#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	sort(a+1,a+m+1);
	int p;
	int max_ans=0;
	for(int i=m;i>=1;i--)
	{
		cout<<1;
		p=i;
		int ans=INT_MAX;
		for(int j=0;j<n;j++) ans = ans & a[i-j];
		max_ans = max(max_ans,ans);
	}
	cout<<max_ans;
	return 0;
}
