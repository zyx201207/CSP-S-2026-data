//GZ-J00252 贵阳市第十七中学 吴芸智
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0;
	int a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<1;
	else
	{
	    cout<<0<<0<<0<<0;
	    return 0;
    }
	int s,s1;
	s=a1[0]*10+a1[1];
	s1=b1[0]*10+b1[1];
	if(s1!=s)
	{
	    cout<<0<<0<<0;
	    return 0;
    }
	else cout<<1;
	char c=a1[2];
	if('A'<=c&&c<='C'&&'A'<=b1[2]&&b1[2]<='C') cout<<1;
	else if('D'<=c&&c<='F'&&'D'<=b1[2]&&b1[2]<='F') cout<<1;
	else cout<<0;
	char w,r;
	w=c-1;
	r=c+1;
	if(b1[2]==w||b1[2]==r)
	{
		if(b1[2]=='D'&&a1[2]=='C')
		{
		    cout<<0;
		    return 0;
	    }
	    	if(b1[2]=='C'&&a1[2]=='D')
		{
		    cout<<0;
		    return 0;
	    }
	    cout<<1;
	}
	else cout<<0;
	return 0;
}
