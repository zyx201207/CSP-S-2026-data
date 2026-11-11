#include<bits/stdc++.h>
using namespace std;

int a1[200005],a2[200005];
char c1[200005],c2[200005];

int main()
{
//	freopen("C:/Users/Administrator/Desktop/string/string6.in","r",stdin);
//	freopen("C:/Users/Administrator/Desktop/string.txt","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,o,p;
	long long ans,i,j;
	bool flag;
	memset(a1,0,sizeof(a1));
	memset(a2,0,sizeof(a2));
	ans=0;
	flag=true;
	cin>>n;
	cin>>a1[0]>>c1[0];
	a2[n-1]=a1[0];
	c2[n-1]=c1[0];
	for(i=1; i<n; i++)
	{
		cin>>a1[i]>>c1[i];
		a2[n-i-1]=a1[i];
		c2[n-i-1]=c1[i];
		if(c1[i]!=c1[i-1])
		{
			flag=false;
		}
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	i=0;
	j=0;
	o=0;
	p=0;
	while(1)
	{
		if(c1[o]!=c2[p])
		{
			ans++;
//			cout<<i<<" "<<o<<"  "<<j<<" "<<p<<endl;
		}
		i++;
		j++;
		if(i>=a1[o])
		{
			i-=a1[o];
			o++;
		}
		if(j>=a2[p])
		{
			j-=a2[p];
			p++;
		}
		if(o+p>=n)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
//	for(int i=0; i<n; i++)
//	{
//		cout<<a1[i]<<" "<<c1[i]<<"  "<<a2[i]<<" "<<c2[i]<<endl;
//	}
//	cout<<m/2+m%2<<endl;
