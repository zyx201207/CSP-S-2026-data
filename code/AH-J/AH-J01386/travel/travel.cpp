#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int sum=0,ans=0;
	sum=(b[0]-'0')*10+(b[1]-'0');
	ans=(d[0]-'0')*10+(d[1]-'0'); 
	if(sum==ans)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	char i=b[2],j=d[2];
	if(i>j)
	{
		swap(i,j); 
	}
	if(i<'D'&&j<'D'||i>'C'&&j>'C')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(j-i==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
/*
Trick||Treat!
2026/10/31 8£º49  
¹êËäÊÙ
²Ü²Ù
Éñ¹êËäÊÙ£¬ÓÌÓÐ¾¡Ê± 
*/
