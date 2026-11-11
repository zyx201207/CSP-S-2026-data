#include <bits/stdc++.h> 
using namespace std;

int RB[100005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>RB[i];
		return 0;
	}
	for(int i=1;i<=m;i++) 
	{
		for(int j=1;j<=n;i++)
		{
			RB[j]+=1;
			if(RB[n]==RB[j])
			cnt++;
		}
		
	}
	cout<<cnt;
	return 0;
}
