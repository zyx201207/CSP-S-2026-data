#include<bits/stdc++.h>
using namespace std;

vector<int>a1,c1,g;

int main()
{
	freopen("C:/Users/Administrator/Desktop/string/string3.in","r",stdin);
//	freopen("C:/Users/Administrator/Desktop/string.txt","w",stdout);
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	long long ans,i,j,m;
	char c;
	bool flag;
	ans=0;
	flag=true;
	cin>>n;
	cin>>i>>c;
	a1.push_back(i);
	c1.push_back(c);
	for(i=1; i<n; i++)
	{
		cin>>j>>c;
		a1.push_back(i);
		c1.push_back(c);
		if(c1[i]!=c1[i-1])
		{
			flag=false;
		}
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<a1[i]; j++)
		{
			g.push_back(c1[i]);
		}
	}
	i=0;
	m=g.size();
	while(1)
	{
		if(g[i]!=g[m-i-1])
		{
			ans++;
		}
		if(i>=m/2)
		{
			break;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
//	for(int i=0; i<n; i++)
//	{
//		cout<<a1[i]<<" "<<c1[i]<<"  "<<a2[i]<<" "<<c2[i]<<endl;
//	}
//	cout<<m/2+m%2<<endl;
