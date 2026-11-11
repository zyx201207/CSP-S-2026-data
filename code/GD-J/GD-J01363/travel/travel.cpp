#include<bits/stdc++.h>
using namespace std;

string a,b,aa,bb;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>aa>>b>>bb;
	if(a==b)
	{
		cout<<"1";
		if(aa[0]==bb[0]&&aa[1]==bb[1])
		{
			cout<<"1";
			char aaa=aa[2],bbb=bb[2];
			if(aaa>=65&&aaa<=67&&bbb>=65&&bbb<=67)
			{
				cout<<"1";
				if(abs(aaa-bbb)==1) cout<<"1";
				else cout<<"0";
			}
			else if((aaa==68&&bbb==69)||(aaa==69&&bbb==68)) cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else if(a!=b) cout<<"0000";
	
	return 0;
} 
