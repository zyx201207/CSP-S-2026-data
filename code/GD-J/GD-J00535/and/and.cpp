#include<bits/stdc++.h>
using namespace std;
int cmp(string a,string b)
{
	if(a.size()>b.size())
	{
		return a>b;
	}
	else
	{
		if(a>b)
		{
			return a>b;
		}
		else
		{
			return a<b;
		}
	}
}
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","W",stdout);
 	long long a,b,ls,max=-1,ls1;
	cin >> a >> b;
	vector<int> c;
	vector<string> d;
	for(int i = 0;i<a;i++)
	{
		cin >> ls1;
		c.push_back(ls1);
		ls=ls1;
		d.push_back("");
		while(ls!=0)
		{
			d[i]+=ls%2+'0';
			ls/=2;
		}
		reverse(d[i].begin(),d[i].end());
	}
	sort(d.begin(),d.end(),cmp);
	for(int i = 0;i<b;i++)
	{
		ls=0;
		ls1=1;
		for(int j = a-1;j>0;j--)
		{
			ls+=(d[i][j]-'0')*ls1;
			ls1*=2;
		}
		c[i]=ls;
	}
	for(int i = a-1;i>a-1-b;i--)
	{
		max=max&c[i];
	}
	cout << max;
	//fclose(stdin),fclose(stdout);
} 
