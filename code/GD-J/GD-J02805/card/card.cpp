#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	int n,m;
	cin >> n >> m;
	int c[n],cnt[m]={0};
	for(int i=0;i<m;i++) cnt[i] = 0;
	for(int i=0;i<n;i++)
	{
		cin >> c[i];
	}
	for(int i=0;i<n;i++)
	{
		int cnt1[m]={0};
		for(int j=0;j<m;j++) cnt1[j] = 0;
		for(int j=i;j<n;j++)
		{
			cnt1[(c[j]-1)]++;
		}
		for(int j=0;j<m;j++)
		{
			if((cnt1[j]%2)!=0) cnt[j]++;
		}
	}
	return 0;
}
