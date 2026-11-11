#include<bits/stdc++.h>
using namespace std;
int n,a;
string s,c;
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		} 
	}
	int l=s.size();
	int x=0,y=l-1;
	while(x<y)
	{
		if(s[x]!=s[y])
		{
			sum++;
			x++;
			y--;
		}
		else
		{
			x++;
			y--;
		}
	} 
	cout<<sum;
	return 0;
}
