#include <bits/stdc++.h>
using namespace std;
string s="";

int Count()
{
	int cnt=0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])	cnt++;
	}
	return cnt;`
}

int main()
{
	freopen("string.in","r",stdin);
s	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)	s+=c;
	}
	cout<<Count();
	return 0;
}
//#include <bits/stdc++.h>
//#define MAXN int(2e5+5)
//using namespace std;
//struct unnamed
//{
//	int begin;
//	int end;
//	char a;	
//}p[MAXN];
//
//int search1(int a)
//{
//	
//}
//
//int main()
//{
//	int n;
//	int CountL=0,CountR=0;
//	cin>>n;
//	long long sum=0;
//	
//	for(int i=1;i<=n;i++)
//	{
//		int a;
//		char c;
//		cin>>a>>c;
//		p[i].begin=p[i-1].end+1;
//		p[i].end=p[i-1].end+a;
//		p[i].a=c;
//		sum+=a;
//	}
//	double mid=(sum+1)*1.0/2.0;
//	for(int i=1;i<=n&&sum-p[i].begin-1>mid;i++)
//	{
//		
//	}
//	return 0;
//}
