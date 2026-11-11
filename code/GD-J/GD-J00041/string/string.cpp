#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],cnt,i,j;
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int ii=1;ii<=n;ii++) cin>>a[ii]>>b[ii];
	for(i=1,j=n;i<=j and j>=i and j!=i;)
	{
		if(a[i]>a[j])
		{
			a[i]-=a[j];
			if(b[i]!=b[j]) cnt+=a[j];
			a[j]=0;
			j--;
		}
		else if(a[i]<a[j])
		{
			a[j]-=a[i];
			if(b[i]!=b[j]) cnt+=a[i];
			a[i]=0;
			i++;
		}
		else if(a[i]==a[j])
		{
			if(b[i]!=b[j]) cnt+=a[i];
			a[i]=0,a[j]=0;
			i++,j--;
		}
	}
	cout<<cnt;
	return 0;
}
