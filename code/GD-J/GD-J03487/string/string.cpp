#include<bits/stdc++.h>
using namespace std;
short kind[600000000];
long long n,ans,len,last,sum,l,r;
char s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>len>>s;
		sum+=len;
		for(int j=last+1;j<=last+len;j++)kind[j]=(int)(s-'a');
		last+=len;
	}
	if(sum%2==1)
	{
		l=sum/2+1;
		r=l;
	}
	else 
	{
		l=sum/2;
		r=l+1;
	}
	while(l>0)
	{
		if(kind[l]!=kind[r])ans++;
		l--;
		r++;
	}
	cout<<ans;
	return 0;	
}
