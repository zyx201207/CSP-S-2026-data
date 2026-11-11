#include<bits/stdc++.h>
using namespace std; 
string s[200005];
bool v[200005];
long long n,m,maxx;
string func(long long a)//10->2
{
	string ss="";
	while(a)
	{
		if(a%2) ss="1"+ss;
		else ss="0"+ss;
		a/=2;
	}
	return ss;
}
long long huan(string ss)//2->10
{
	long long a=0;
	for(int i=0;i<ss.size();i++)
	{
		a*=2;
		if(ss[i]=='1') a+=1;
	}
	return a;
}
string andd(string a,string b)// °´Î»Óë
{
	
	string ss="";
	int z=max(a.size(),b.size())-1;
	int f=1;
	if(a.size()<b.size()) f=0;
	else if(a.size()==b.size()) f=2;
	//a<b f=0   b<a f=1  b==a f=1
	for(int i=min(a.size(),b.size());i<=z;i++)
	{
		if(f==2)
			break;
		if(f==1)
			b="0"+b;
		else
			a="0"+a;
	}
	for(int i=0;i<=z;i++)
	{
		if(a[i]==b[i]&&a[i]=='1')
			ss=ss+"1";
		else
			ss=ss+"0";
	}
	return ss;
}
void dfs(long long t,string k)
{
	if(t==m)
	{
		maxx=max(maxx,huan(k));
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			dfs(t+1,andd(k,s[i]));
			v[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	string c="";
	for(int i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		s[i]=func(a);
		c=max(c,s[i]);
	}
//	for(int i=0;i<n;i++)
//		cout<<s[i]<<" ";
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		v[i]=1;
		dfs(1,s[i]);
		v[i]=0;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
