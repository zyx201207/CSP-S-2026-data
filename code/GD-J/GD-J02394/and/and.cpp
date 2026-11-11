#include<bits/stdc++.h>
#define int long long
using namespace std;
string turn(int x)
{
	bitset<32> b=x;
	string p=b.to_string();
	int len=0;
	for(char &i:p)
	{
		if(i=='0') len++;
		else break;
	}
	return p.substr(len);
}
bool cmp(pair<int,string> a,pair<int,string> b)
{
	int tmpa=__builtin_popcount(a.first),tmpb=__builtin_popcount(b.first);
	if(tmpa>tmpb) return 1;
	else if(tmpa<tmpb) return 0;
	else if(tmpa==tmpb)
	{
		string p=a.second,q=b.second;
		int lenp=p.size(),lenq=q.size();
		if(lenp>lenq) return 1;
		else if(lenp<lenq) return 0;
		else
		{
			for(int i=0;i<lenp;i++)
			{
				if(p[i]=='1' and q[i]=='0') return 1;
				else if(p[i]=='0' and q[i]=='1') return 0;
			}
		}
		return 1;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,ans; cin>>n>>m;
	vector<pair<int,string>> a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=turn(a[i].first);
	}
	sort(a.begin()+1,a.end(),cmp);
	ans=a[1].first;
	for(int i=2;i<=m;i++) ans&=a[i].first;
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
