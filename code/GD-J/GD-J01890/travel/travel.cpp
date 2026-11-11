#include <bits/stdc++.h>
using namespace std;
struct seat{
	int c;
	string s;
}a[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++)
	{
		cin>>a[i].c>>a[i].s;
	}
	if(a[1].c==a[2].c){
		cout<<'1';
		if(a[1].s[0]+a[1].s[1]==a[2].s[0]+a[2].s[1]) 
		{
			cout<<'1';
			if(((a[1].s[2]>='A'&&a[1].s[2]<='C')&&(a[2].s[2]>='A'&&a[2].s[2]<='C'))||((a[1].s[2]=='D'&&a[1].s[2]=='F')&&(a[2].s[2]=='D'&&a[2].s[2]=='F'))) 
			{
				cout<<'1';
				if(abs(a[1].s[2]-a[2].s[2])==1||(a[1].s[2]+a[2].s[2])/2=='E') cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}
