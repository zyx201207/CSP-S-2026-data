#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,n1,sum=0;
	char c;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>n1>>c;
		while(n1--)
		{
			s+=c;
		}
	}
	int l=0,r=s.length()-1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}
