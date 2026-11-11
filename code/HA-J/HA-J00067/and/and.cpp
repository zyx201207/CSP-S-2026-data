#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;

	cin >> n >> m;
	m=n-m;
	vector<int> num(n);
	vector<bool> vis(n);
	int maxx=-1,sum=0;
	for(int i=0; i<n; i++)
	{
		cin >> num[i];
		maxx=max(maxx,num[i]);
	}
	if(m==0)
	{
		maxx=num[0];
		for(int i=1; i<n; i++)
		{
			maxx=maxx&num[i];
		}
//		cout << maxx;
	}
	else
	{

		int mxb=0;
		while(maxx)
		{
			maxx/=2;
			mxb+=1;
		}
		mxb--;
		for(int i=1<<mxb; i>=1; i>>=1) //30
		{
			int inv=0;
			for(int j=0; j<n; j++)//2e5
			{
				if(vis[j]==0)
				{
					inv+=!((i&num[j])/i);
				}
			}
			if(inv<=m)
			{
				sum+=i;
				m-=inv;
				for(int j=0; j<n; j++)
				{
					if(!((i&num[j])/i))
					{
						vis[j]=1;
					}
				}
			}
		}
		cout << sum;
	}
	return 0;
}