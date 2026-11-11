#include<bits/stdc++.h>
using namespace std;
inline long long qbt(const string &a,const string &b)
{
	int sz=a.size(),cnt=0;
	for(int i=0;i<sz;i++)
	{
		if(a[i]!=b[i])cnt++;
	}
	return cnt;
}
inline string gz(string x,const bool &zt)
{
	string ret;
	ret=x;
	reverse(ret.begin(),ret.end());
	if(!zt)return x+ret;
	else
	{
		x.pop_back();
		return x+ret;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n;cin>>n;
	string str,strh,b;
	char s;
	while(cin>>n>>s)strh+=string(n,s);
	str=strh;
	b=strh;
	reverse(strh.begin(),strh.end());
	int ci=str.size()/2;
	for(int i=0;i<ci;i++)str.pop_back();
	for(int i=0;i<ci;i++)strh.pop_back();
	cout<<min(qbt(gz(strh,!(ci&1)),b),qbt(gz(str,!(ci&1)),b));
	return 0;
}
