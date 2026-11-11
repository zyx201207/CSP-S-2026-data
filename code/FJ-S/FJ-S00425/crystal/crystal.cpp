#include<bits/stdc++.h>                                                                                                                                                             
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	int aa=1,b=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>1&&(a[i]-a[i-1])!=1)aa=0;
		if(i>2&&(a[i]-a[i-1])!=(a[i-1]-a[i-2]))b=0;
	}
	if(aa)
	{
		int x=0,ans=0;
	    for(int i=n;i>=1;i--)
	    {
	    	if((x+(n-i))>m)break;
			x+=(n-i);
			ans++; 
	    }
	    cout<<ans;
	    return 0;
	}
	if(b)
	{
		int x=0,ans=0,y=a[2]-a[1];
	    for(int i=n;i>=1;i--)
	    {
	    	if((x+(n-i)*y)>m)break;
			x+=(n-i)*y;
			ans++; 
	    }
	    cout<<ans;
	    return 0;
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=0,y=0;
		for(int j=1;j<=i;j++)
		{
			y=j;
			if(x+(a[i]-a[j])>m)break;
			x+=(a[i]-a[j]);
		}
		ans=max(y,ans);
	}
	cout<<ans;
	return 0;
}
/*
Ë«ºÚ and Ã×ÓÅ and ca and ks and ËþÁø and -0 and °×ÄÁ and ÌìÇà and ÔÆÌð99
484 99
Ð¤È½&ccf 99 
*/
/*
Ich liebe CCF und CCF liebt mich auch.
- Richtig,CCF?
- Ja,ich mag FJ-S00425
Jetzt finde ich etwas lustiges -> 4 und 25 ,entschuldigung fuer 25!!!
Hier sind der Name in XMFLS-JM-C-202501:
Holger Monika Wiebke Sandro Svenja Valentin Freddy Eugen Justus Linus Jette Daniel Robort Leander Finn Rebekka.
Bitte ->Englich -> Do not let me on the Xuanshoudashang,thx.
*/
