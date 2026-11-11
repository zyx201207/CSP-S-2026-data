#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k;
	cin>>k;
	string S;
	int cnt1=0;cnt2=0;cnt3=0;
	int a[1005];
	for (int i = 0; i < n; ++i)
	{
		cin>>S[i];
	}
	for (int j = 0; j <= n; ++j)
	{
		if (S[i]!=k)S.append(k);
		else if (S[i]==k)
		{
			S.erase(i,n-1);
			S.append(k);
		}
		if (S[n-1]==i)++cnt1;
		else if (S[n-1]==i+1)++cnt2;
		else if (S[n-1]==i+2)++cnt3;
	}
	a[0]+=cnt1;
	a[1]+=cnt2;
	a[2]+=cnt3;
	for (int z = 0; z < n; ++z)
	{
		cout<<a[z]<<" ";
	}
	return 0;
}