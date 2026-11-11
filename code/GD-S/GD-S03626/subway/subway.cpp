#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q,b[100005];
vector<int> a[100005];  
int main()
{
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];

	}
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int z,x;
			cin>>z>>x;
			a[k].push_back(z); 
			a[k].push_back(x); 
		}
	}
	int sum=0;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		{
			sum+=a[i]*2;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
