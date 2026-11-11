#include<bits/stdc++.h>
using namespace std;

string v[10000005];
int a[10000005];
int tmp=0;
string str;

string exchange(int n)
{
	int x=n,cnt=0;
	while(x>0)
	{
		str+=char((x%2)+48);
		cnt++;
		x/=2;
	}
	a[tmp]=cnt;
	return str;
}


int main()
{
	int n,m,a;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		tmp++;
		cin>>a;
		v[i]=exchange(a);
	}
	cout<<v[1];
	return 0;
}
