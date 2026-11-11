#include<bits/stdc++.h>
using namespace std;
long long a,aa[200100],s,h,g,f,ff[200100],gg[200100],rr,tt,r,t;
char ss[200100],fff[200100],ggg[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>aa[i];
		cin>>ss[i];
		s=s+aa[i];
	}
	s=s/2;
	h=0;
	for(int i=1;i<=a;i++)
	{
		ff[++f]=aa[i];
		fff[f]=ss[i];
		if(h+aa[i]>=s)
		{
			ff[f]=s-h;
			break;
		}
		h=h+aa[i];
	}
	h=0;
	for(int i=a;i>=1;i--)
	{
		gg[++g]=aa[i];
		ggg[g]=ss[i];
		if(h+aa[i]>=s)
		{
			gg[g]=s-h;
			break;
		}
		h=h+aa[i];
	}
	h=0;
	while(r!=s||t!=s)
	{
		if(r<t)
		{
			rr++;
			r=r+ff[rr];
			if(fff[rr]!=ggg[tt])
			{
				if(r>t)
				h=h+t-(r-ff[rr]);
				else
				h=h+ff[rr];
			}
		}
		else
		{
			tt++;
			t=t+gg[tt];
			if(ggg[tt]!=fff[rr])
			{
				if(t>r)
				h=h+r-(t-gg[tt]);
				else
				h=h+gg[tt];
			}
		}
	}
	cout<<h;
}
