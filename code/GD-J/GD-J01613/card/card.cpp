#include<bits/stdc++.h>
using namespace std;
queue<char> q,q2;
string s;
int main()
{
	freopen("card4.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m,a[300005];
	char c;
	cin>>n>>m;
	for(int i = 0;i<n;i++)
	{
		cin>>c;
		q.push(c);
	}
	for(int i = 0;i<n;i++)
	{
		q2=q;
		s="";
		for(int j = 0;j<i;j++)
		{
			q2.pop();
		}
		while(!q2.empty())
		{
			if(s.find(q2.front())!=-1)
			{
				s.erase(s.find(q2.front()));
				s+=q2.front();
				q2.pop();
				continue;
			}
			s+=q2.front();
			q2.pop();
		}
		for(int i = 0;i<s.size();i++)
		{
			a[s[i]-'0']++;
//			cout<<s[i]<<' ';
		}
//		cout<<endl;
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<a[i]<<' ';
	}
	return 0;
}

