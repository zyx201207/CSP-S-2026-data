#include<bits/stdc++.h>
using namespace std;
string two(int k)
{
	string rtn;
	while(k!=0)
	{
		if(k%2==1) rtn='1'+rtn;
		else rtn='0'+rtn;
		k/=2;
	}
	return rtn;
}
int yu(string o,string p)
{
	string op;
	int lth=max(o.size(),p.size());
	int sth=min(o.size(),p.size());
	int rtn=0;
	if(o.size()>p.size()) op=o;
	else op=p;
	int j;
	for(int i=lth-1;i>=lth-sth-1;i--)
	{
		if(o.size()>p.size())
		{
			j=i-(lth-p.size());
			if(o[i]=='1'&&p[j]=='1') op[i]='1';
			else op[i]='0';
		}
		else
		{
			j=i-(lth-o.size());
			if(p[i]=='1'&&o[j]=='1') op[i]='1';
			else op[i]='0';
		}
	}
	for(int i=lth-1;i>=0;i--)
	{
		if(op[i]=='1') rtn+=pow(2,lth-i-1);
	}
	return rtn;
}
int count1(string str)
{
	int rtn;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1') rtn++;
	}
	return rtn;
}
int n,m;
string tst;
struct number
{
	int num;
	string tw;//指二进制值(two) 
	int cnt1;
};
bool bjq(number x,number y)
{
	return x.cnt1>y.cnt1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<number> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].num;
		a[i].tw=two(a[i].num);
		a[i].cnt1=count1(a[i].tw);
		cout<<a[i].tw<<endl;
	}
	sort(a.begin(),a.end(),bjq);
	cout<<yu(a[0].tw,a[1].tw);
	return 0;
}
