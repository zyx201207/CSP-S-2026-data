//准考证号：GZ-J00188 学校：遵义市新蒲新区滨湖中学  姓名：袁乙文
#include<iostream>
#include<cstdio>
#include<string> 
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,m,ans=0;
	cin >> n >> m;
	string s;
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		char l;cin>>l;
		for(int j=0;j<k;j++)
		{
			s[i]==l;
		}
	}
	if(s.size()%2==0)
	{
		char ch=s[0];
		for(ll i=1;i<s.size();i++)
		{
			if(s[i]!=ch)
			{
				s[i]=ch;
				ans++;
			}
			else continue;
		}
	}
	else 
	{
		char fasd=s[s.size()/2+1];
		for(ll i=s.size()/2+1;i<s.size();i++)
		{
			if(s[i]!=fasd) 
			{
				s[i]=fasd;
				ans++;
			}
			else continue;
		}
	}
	cout << ans;
	
	return 0;
}
