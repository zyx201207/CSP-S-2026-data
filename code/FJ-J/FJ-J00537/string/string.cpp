#include<bits/stdc++.h>
using namespace std;
int s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	cin>>n;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string ss="";
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++)
			ss+=c;
	}
	int l=0,r=ss.size()-1;
	while(l<=r)
	{
		if(ss[l]!=ss[r])s++;
		l++,r--;
	} 
	cout<<s;
	return 0;
} 
