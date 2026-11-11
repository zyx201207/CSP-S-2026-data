#include<bits/stdc++.h>
using namespace std;
int x1[200005];
char x2[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ber=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x1[i]>>x2[i];
	int n1=1,n2=n,l1=0,l2=0;
	while(n1<=n2)
	{
		if(l1==0)
		{
			l1=x1[n1];
			n1++;
		}
		if(l2==0)
		{
			l2=x1[n2];
			n2--;
		}
		if(l1>=l2)
		{
			if(x2[n1-1]!=x2[n2+1]) ber+=l2;
			l1-=l2;
			l2=0;
		}
		else
		{
			if(x2[n1-1]!=x2[n2+1]) ber+=l1;
			l2-=l1;
			l1=0;
		}
	}
	cout<<ber;
	return 0;
}
