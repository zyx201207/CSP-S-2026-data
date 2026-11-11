#include<bits/stdc++.h>
using namespace std;
struct st
{
	int shu;
	char m;
}a[200005];
int main()
{	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long total=0;
	string s;
	bool flag=true;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].shu>>a[i].m;
		if(i!=1)
		{
			if(a[i].shu!=a[i-1].shu)flag=false;
		}
	}
	int sc=0,mid,b=1,e;
	if(flag)
	{	mid=n*1.0/2;
		sc=n;
		if(sc%2!=0)
		{
			e=b+mid+1;
		}else
		{
			e=b+mid;
		}
		for(b;b<=mid;b++)
		{
			if(a[b].m!=a[e].m)total++;
			e++;
		}total*=a[1].shu;
	}else
	{	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i].shu;j++)
			{	
				sc++;
				s[sc]=a[i].m;
			}
		}mid=1.0*sc/2;
		if(sc%2!=0)
		{
			e=b+mid+1;
		}else
		{
			e=b+mid;
		}
		for(b;b<=mid;b++)
		{
			if(s[b]!=s[e])total++;	
			//cout<<e<<' '<<b<<' '<<total;		
			e++;			
		}
	}
	cout<<total;
	fclose(stdin);	
	fclose(stdout);	
	return 0;
}
/*
4
1 a
2 b
2 a
2 c
*/

