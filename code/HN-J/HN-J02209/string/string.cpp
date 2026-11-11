#include<bits/stdc++.h>
using namespace std;
long long n,ii[200005],len=0,cs=0,kkksc03=0;//kkksc03：关我何事？！ 
char cc[200005];
string c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool pianfen=true;//用来骗分的^w^ ~
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ii[i]>>cc[i];
		if(i>1)
		{
			if(ii[i]!=ii[i-1])
			{
				pianfen=false;
			}
		}
	}
	if(pianfen==true)//可以骗到分啦^W^ ~
	{
		for(int i=1;i<=n/2;i++)
		{
			if(cc[i]!=cc[n-i+1])
			{
				kkksc03=kkksc03+ii[1];
			}
		}
	}
	if(pianfen==false)//骗不了分了o^o ~ 
	{
		for(int i=1;i<=n;i++)
		{
			while(ii[i]--)
			{
				c[len]=c[len]+cc;
				len++;
			}
		}
	}
	
	for(int i=0;i<len/2;i++)
	{
		if(c[i]!=c[len-i-1])
		{
			kkksc03++;
		}
	}
	cout<<kkksc03;
	return 0;
}
/*

*/
