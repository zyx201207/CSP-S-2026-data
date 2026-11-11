#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);      //¼ÇµÃÉ¾×¢ÊÍ    OK
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int li=1,ri=n;
	long long ln=a[1],rn=a[n];
	long long ans=0;
	while(li<ri)
	{
		int mi=min(ln,rn);
		if(c[li]!=c[ri])ans+=mi;
		ln-=mi;
		rn-=mi;
		if(!ln)
		{
			li++;
			ln=a[li];
		}
		if(!rn)
		{
			ri--;
			rn=a[ri];
		}
	}
	cout<<ans;
	return 0;
}
