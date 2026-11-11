#include<bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define MAXB 40

int popcnt(int x)
{
	int ans=0;
	while(x)
	{
		ans++;
		x=x&(x-1);
	}
	return ans;
}

bool cmp(int x,int y)
{
	return x>y;
}

int n,m;
int a[MAXN];
vector<int> v[MAXB];
long long p[30][MAXN];
long long ans=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//freopen("and1.in","r",stdin);
	//freopen("and1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int cnt=popcnt(a[i]);
		v[30-cnt].push_back(a[i]);
	}
	for(int i=0;i<=30;i++)
	{
		sort(v[i].begin(),v[i].end(),cmp);
	}
	for(int i=0;i<=30;i++)
	{
		for(int j=0;j<v[j].size();j++)
		{
			if(j==0)	p[i][j]=v[i][j];
			else p[i][j]=p[i][j-1]&v[i][j];
		}
	}
	int idx=0;
	while(m)
	{
		if(v[idx].size()==0)
		{
			idx++;
			continue;
		}
		int x=min(m,(int)v[idx].size());
		m-=x;
		if(ans==0)	ans=p[idx][x];
		else ans=ans&p[idx][x];
		idx++;
	}
	cout<<ans<<endl;
	
	return 0;
}
