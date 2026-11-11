#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int ans;
int time_;
int a[200100];
bool b[200100];
void pl()
{	
	time_++;
	if(time_>m)
	{
		return;
	}
	for (int i=1; i<=n; i++)
	{
		int next=a[i];
		if(b[i]!=1)
		{
			b[i]=1;
			ans++;
			pl();
		}
	}
}
int main()
{
	int maxn=-1;
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	
	cout << maxn;
	return 0;
}
