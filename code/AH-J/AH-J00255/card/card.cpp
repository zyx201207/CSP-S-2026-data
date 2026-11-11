#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300001];
vector<int> ca;
bool findv(int x)
{
	for(int i = 0; i < ca.size(); i++)
	{
		if(ca[i]==x)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1;
	while(l<=n)
	{
		if(!findv(a[l]))
		{
			ca.push_back(a[l]);
			b[a[l]]++;
		}
		else
		{
			ca.erase(ca.begin()+l-1,ca.end());
			ca.push_back(a[l]);
		}
		l++;
	}
	for(int i = 1; i <= m; i++)
	{
		if(b[i]>0)
			cout <<b[i]<<" ";
	}
	return 0;	
}
