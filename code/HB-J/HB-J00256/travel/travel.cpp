#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[5]={1,1,1,0,0},n=4;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		n--;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			n--;
			if(a[s1[2]-'A']==a[s2[2]-'A'])
			{
				cout<<1;
				n--;
				if(abs(s1[2]-s2[2])==1)
				{
					cout<<1;
					n--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<0;
	return 0;
}
