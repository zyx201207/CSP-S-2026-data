#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n,m;
string s;
string t;
string p;
string d;
int ans;
char c;
int a[N],b[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s += a[i]+='0';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<s.size();j++)
		{
			if(t.find(s.substr(j,1)) == -1)
			{
				t += s.substr(j,1);
			}
			else
			{
				t.erase(t.find(s.substr(j,1)),t.size());
				t+=s.substr(j,1);
			}
				
		}
//		cout << t;
		p += t;
		t = "";
		s.erase(0,1);
	}
	d = "1";
	for(int i=1;i<=m;i++)
	{
//		d += i += '0';
		for(int j=0;j<p.size();j++)
		{
			if(p.find(d) != -1)
			{
				ans += 1;
				p.erase(p.find(d),p.find(d)+1);
			}
			else if(p.find(d) == -1)
			{
				break;
			}
		}
		d = "";
		cout << ans << " ";
	}
	return 0;
} 
