#include<bits/stdc++.h>
using namespace std;
#define itn int
#define ll long long
int n;
string str;
string ustr;
int res;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tis;
		char us;
		cin>>tis>>us;
		while(tis--)
			str=str+us,ustr=us+ustr;
	}
	if(str==ustr)
	{
		cout<<"0";
		return 0;
	}
	ll len=str.size();
	string strf=str.substr(0,len>>1),strb=ustr.substr(0,len>>1);
	for(int i=0;i<(len>>1);i++)
		if(strf[i]!=strb[i])
			res++;
	cout<<res;

	return 0;
}

