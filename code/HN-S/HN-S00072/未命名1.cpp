#include<bits/stdc++.h>
using namespace std;

int a[2][12]= {{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
check(int yy)
{
	if(yy%400==0)
	{
		return 1;
	}
	if(yy%100!=0&&yy%4==0)
	{
		return 1;
	}
	return 0;
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int yy,mm,dd,n,m;
	string s;
	cin>>s;
	n=s.size();
	yy=stoi(s.substr(0,n-4));
	mm=stoi(s.substr(n-4,2));
	dd=stoi(s.substr(n-2,2));
	cin>>m;
	for(int i=0; i<m; i++)
	{
		dd++;
		if(dd>a[check(yy)][mm-1])
		{
			dd-=a[check(yy)][mm-1];
			mm++;
		}
		if(mm>12)
		{
			mm-=12;
			yy++;
		}
	}
	cout<<yy<<(mm<10?"0":"")<<mm<<(dd<10?"0":"")<<dd;
	return 0;
}

