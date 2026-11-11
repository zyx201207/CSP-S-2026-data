#include <bits/stdc++.h>
using namespace std;
int n,m,b[20000000],maxn=-1,w;
bool a[20000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> w;
			maxn=max(w,maxn);
		}
		cout << maxn;
		return 0;
	}
	int num=m-1;
	for(int i=1;i<=n;i++)
	{
		cin >> b[i];
		if(a[b[i]]==1 && m>1)
		{
			maxn=b[i];
			i--;
			n--;
			num--;
			continue;
	    }
		a[b[i]]=1;
	}
	sort(b+1,b+n+1);
	if(maxn==0)
	{
		maxn=b[n];
		n--;
    }
	for(int i=1;i<=num;i++)
	{
		b[n]&=b[n-1];
		maxn=b[n];
		n--;
	}
	cout << maxn;
	return 0;
} 
