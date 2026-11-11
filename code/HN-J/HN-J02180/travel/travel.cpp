#include <bits/stdc++.h>
using namespace std;

int MyStoi(string s)
{
	int sum=0;
	for(int i=0;i<2;i++)
		sum=sum*10+s[i]-'0';
	return sum;
}

int find(const char a,const string& b)
{
	for(int i=0;i<b.size();i++)
		if(a==b[i])	return true;
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string a_1,b_1;
	cin>>a>>a_1>>b>>b_1;
	
	if(a!=b)
	{
		cout<<"0000";
		return 0;
	} 
	cout<<"1";
	if(MyStoi(a_1)==MyStoi(b_1))
	{
		cout<<"1";
		if((find(a_1[2],"ABC")&&find(b_1[2],"ABC"))||(find(a_1[2],"DF")&&find(b_1[2],"DF")))
		{
			cout<<1;
			if(a_1[2]-1==b_1[2]||a_1[2]+1==b_1[2]) cout<<"1";
			else cout<<"0";
		}else cout<<"00";
	} else cout<<"000";
	
	
	return 0;
}
