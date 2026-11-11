#include<bits/stdc++.h>
using namespace std;
long long a,s,d,f,x;
int main ()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin  >> a >> s;
	long long qwe[a],xc[s],ww[s];
	for(int i=0;i<a;i++)
	{
		cin >> qwe[i];
		if(i<s)
		{
			xc[i]=0;
			ww[i]=0;
		}
	}
for(int x=0;x<a;x++)
{
	d=x;
	for(int i=d;i<s;i++)
	{
		for(int j=i-1;j>=d;j--)
		{
			if(qwe[i]==qwe[j])
			{
				d=i;
			}
		}
	}
	for(int i=d;i<s;i++)
	{
		ww[i]++;
	}
}
for(int i=0;i<s;i++)
{
	cout<<ww[i]<<' ';
}
return 0;
}

