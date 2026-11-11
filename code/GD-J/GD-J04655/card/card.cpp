#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10,M=5e5+10;
int n,m,a[M],sum[N],w[M],len;
vector<int> v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=500000;i++)
		w[i]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v.push_back(a[i]);
	}
	for(int t:v)
	{
		if(w[t]!=-1)
		{
			int new_a[M];
			for(int j=1;j<=w[t];j++)
				new_a[j]=a[j];
			for(int j=w[t]+1;j<=len;j++)
			{
				v.push_back(a[j]);
				w[a[j]]=-1;
			}
			len=w[t];
			memcpy(new_a,a,sizeof(a));
		}
		else
		{
			w[t]=++len;
			a[len]=t;
		}
		for(int j=1;j<=len;j++)
			sum[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<" ";
	return 0;
}
