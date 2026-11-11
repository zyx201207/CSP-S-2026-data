#include<bits/stdc++.h>
using namespace std;
int change=0;
int chan(string s)
{
	int l=0,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r]) change++;
		l++;
		r--;
	}
	return change;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out", "w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int k;
		string c;
		cin>>k>>c;
		for(int j=1;j<=k;j++)
		{
			s+=c;
		}
	}
	cout<<chan(s);
	return 0; 
}

