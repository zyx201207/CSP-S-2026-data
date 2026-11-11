#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int o;
	char c;
}a[200200]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++)
	{
		cin>>a[i].o>>a[i].c;
		for(int j=0;j<a[i].o;j++)
		{
			s+=a[i].c;
		}
	}
	ll r=s.size()-1;
	ll l=0;
	ll sum=0;
	while(l<=r)
	{
		if(l==r)
		{
			break;
		}
		if(s[l]==s[r])
		{
			l++;
			r--;
			continue;
		}
		else
		{
			s[r]=s[l];
			l++;
			r--;
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
