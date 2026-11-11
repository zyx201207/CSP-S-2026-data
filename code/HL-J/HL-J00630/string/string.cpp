#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,pushback,l=0,r,cnt;
char pc;
vector<char>a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>pushback>>pc;
		for(int j=0;j<pushback;j++)
		{
			a.push_back(pc);
		}
	}
	r=a.size()-1;
	while(l<r)
	{
		if(a[l]!=a[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
