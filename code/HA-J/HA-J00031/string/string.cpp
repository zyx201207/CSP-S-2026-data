#include<bits/stdc++.h>
using namespace std;
long long int n,s1,s2;
char c;
string s;
void f(string x)
{
	for(int i=s1,j=n;i++,j--;i<j)
	{
		if(x[i]!=x[j])
		{
			++s2;
		}
	}
	cout<<s2;
}
struct node
{
	long long b;
}a[100000001];
int main()
{
	ios::sync_with_stdio; 
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].b>>c;
		for(int j=1;j<=a[i].b;j++)
		{
			s+=c;
		}
	}
	s1=s.size();
	if(s1%2==1) s1=s1/2;
	else s1/=2;
	f(s);
	return 0; 
}
/*
6
2 1000000000 a
3 1000000000 a
4 1000000000 a
5 1000000000 b
6 1000000000 b
71000000000 b

*/
