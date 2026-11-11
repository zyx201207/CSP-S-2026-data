#include<bits/stdc++.h>
using namespace std;
string y,x,b,a;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x)
	{
		cout<<1;
		int q=b[0]*10,w=b[1];
		int e=y[0]*10,r=y[1];
		int cnt=q+w,ans=e+r;
		if(cnt==ans)
		{
			cout<<1;
			char p=b[2],o=y[2];
			if(p=='A'||p=='B'||p=='C'&&o=='A'||o=='B'||o=='C')cout<<1;
			else if(p=='D'||p=='F'&&o=='D'||o=='F')cout<<1;
			else cout<<0;
			if(p=='A'&&o=='B'||p=='B'&&o=='A'||p=='B'&&o=='C'||p=='D'&&o=='F'||p=='F'&&o=='D')cout<<1;
			else cout<<0;	
		}	
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
