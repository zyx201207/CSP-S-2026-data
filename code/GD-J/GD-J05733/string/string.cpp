#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,cnt=0;
	string c=" ",d="",e="";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b;
		cin>>c;
		for(int j=0;j<b;j++)
	{
		d=d+c;
	}
	}
	for(int i=d.size()-1;i>=0;i--)
	{
		e=e+d[i];
	}
	for(int i=0;i<=d.size();i++)
	{
		if(d[i]!=e[i])
		{
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}
