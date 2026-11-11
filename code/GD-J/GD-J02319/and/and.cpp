#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[20005],maxx,ans;
void dd(int x,int y)
{
	if(x == m)
	{
		maxx= max(ans,maxx);
		return;
	}
	long long anns = ans;
	anns &= a[y];
	if(x == 0)  anns = a[y];
	dd(x+1,y+1);
	anns = ans;
	dd(x,y+1);	
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n;
	cin >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dd(0,1);
	cout << maxx;
	return 0;
}
