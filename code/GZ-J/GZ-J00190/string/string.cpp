//GZ-J00190 南明区山水中学 赵宇涵 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0,m=0;
	string s,r="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		cnt+=a;
		for(int i=1;i<=a;i++)
		{
			r+=s;
		}
	}
	for(int i=1;i<=cnt;i++)
	{

		if(r[i]!=r[cnt-i])
		{
			r+=r[i];
			m++;
		}
	}
	cout<<m;
	return 0;
}

