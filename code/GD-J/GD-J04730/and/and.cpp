#include<bits/stdc++.h>
using namespace std;
int n,m,ans; 
int b[200001][31];
bool flag[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	for(int i=1;i<=200000;i++)
		flag[i]=1;
	cin>>n>>m;
	for(int i=1,a;i<=n;i++)
	{
		cin>>a;
		int j=0;
		while(a)
		{
			b[i][j]=a%2;
			a/=2;
			j++;	
		}
	}
	for(int i=30;i>=0;i--)
	{
		ans*=2;
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(b[j][i]&&flag[j])
				cnt++;
		if(cnt>=m)
		{
			for(int j=1;j<=n;j++)
				if(!b[j][i])
					flag[j]=0;
			ans++;
		}		
	}
	cout<<ans;
	return 0;
} 
