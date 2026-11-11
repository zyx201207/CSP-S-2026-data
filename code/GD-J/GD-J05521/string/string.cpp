#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 200005; 
long long inx[MAXN];
char inc[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	vector<pair<long long,char>> a;
	long long m = 0;
	long long len = 0;
	string s = "";
	for(int i = 1;i <= n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		while(x--)
			s+=c;
	}
	string s1 = "";
	for(int i = s.length()-1;i>=0;i--)
		s1 += s[i];
	int ans = 0;
	for(int i = 0;i < s.length()/2;i++)
	{
		if(s[i] != s[s.length()-i-1])
			ans++;
	}
	cout<<ans;
	return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 200005; 
long long inx[MAXN];
char inc[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	vector<pair<long long,char>> a,b,d;
	long long m = 0;
	long long len = 0;
	
	for(int i = 1;i <= n;i++)
	{
		cin>>inx[i]>>inc[i];
		m+=inx[i];
	}
	bool even = (m%2==0);
	bool flag = false;
	int mid = 0;
	a.push_back({0,'0'});
	b.push_back({0,'0'});
	for(int i = 1;i <= n;i++)
	{
		int x = inx[i];
		char c = inc[i];
		if(even && len < m/2 && len+x>m/2)
		{
			if(m/2-len >=1)
				a.push_back({m/2-len,c});
			mid = a.size()-1;
			flag = true;
			if(x-m/2+len>=1)
				d.push_back({x-m/2+len,c});
		}
		else if((!even) && len <= m/2 && len+x>m/2)
		{	
			if(m/2-len >=1)
				a.push_back({m/2-len,c});
			mid = a.size()-1;
			flag = true;
			if(len+x-(m/2+1) >= 1)
				d.push_back({len+x-(m/2+1),c});
		}	
		else
		{
			if(flag)
				d.push_back({x,c});
			else
				a.push_back({x,c});
		}
		len+=x;	
	}
	int i = d.size()-1,j= 1,cmp1 = a[1].first,cmp2 = d[i].first;
	while(i>=0)
	{
		if(cmp2>cmp1)
		{
			b.push_back({cmp2-cmp1,d[i].second});
			d[i].first-=cmp2-cmp1;
			j++;
			cmp1 = a[j].first;
		}
		else
		{
			b.push_back({d[i].first,d[i].second});
			i--;
			cmp2 = d[i].first;
		}
	}	
	for(auto i:b)
		cout<<i.first<<' '<<i.second<<endl;
	return 0;
}
*/ 
