//∞≤À≥∑ÔªÀ—ß–£ ¡ı‘∂Íª GZ-J00157
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt=0;
	string s,ss,c,cc;
	cin>>s>>ss>>c>>cc;
		if(s[0]!=c[0]||s[1]!=c[1])
		{
			cout<<0;
			cout<<'0';
			cout<<'0';
			cout<<'0';
			return 0;
		}
	    else cout<<1;
	    if(ss[0]!=cc[0]||ss[1]!=cc[1])
		{
			cout<<0<<'0'<<'0';
			return 0;
		}
	    else cout<<1;
	    if((ss[2]=='D'||cc[2]=='D')&&(ss[2]=='F'||cc[2]=='F'))
	    {
	    	cout<<11;
		}
		else if((ss[2]!='D'&&cc[2]!='D')&&(ss[2]!='F'&&cc[2]!='F'))
		{
			cout<<1;
			if((ss[2]-'B'==cc[2]-'A')||(ss[2]-'A'==cc[2]-'B'))cout<<1;
			else cout<<0;
		}
		else cout<<0<<'0';
	return 0;
}
