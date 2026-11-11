#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	long long num=0;
	for(int i=1; i<=n; i++)
	{
		long long a;
		char c;
		cin >> a >> c;
//		cout<<"*";
		while(a--)
		{
			s+=c;
		}
	}
	int p=0;
	int aa=s.size();
	aa/=2;
	cout<<aa<<"**";
	while(aa--)
	{
		if(s[aa]!=s[s.size()-aa-1])
		{
			num++;
		}
//		p++;
	}
	cout<<num;
	return 0;
}
