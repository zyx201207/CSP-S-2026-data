#include<bits/stdc++.h>
using namespace std;

int n,a[200005];
char c[200005];
long long l=0,m=0;

int main()
{	
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l=l+a[i];
	}
	while(l>0)
	{
		int i=1,j=n;
		if(i==j)
		{
			m+=(a[i]/2);
			l=l-(a[i]/2+1);
			break;
		}
		if(a[i]==a[j])
		{
			if(c[i]!=c[j])
			m+=a[i];
			l=l-(a[i]*2);
			i++;
			j--;
		}
		else {if(a[i]>a[j])
			{
				if(c[i]!=c[j])
				m+=a[j];
				l=l-(a[j]*2);
				a[i]=a[i]-a[j];
				j--;
			}
			else {
					if(c[i]!=c[j])
					m+=a[i];
					l=l-(a[i]*2);
					a[j]=a[j]-a[i];
					i++;
				}}
	}
	cout<<m;
	return 0;
}
