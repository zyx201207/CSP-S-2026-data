#include<iostream>
using namespace std;
long long a[200001];
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int p=1,q=n;
	long long s=0;
	while(p<q)
	{
		if(a[p]<a[q])
		{
			if(c[p]!=c[q])s+=a[p];
			a[q]-=a[p];
			p++;
		}
		else
		{
			if(c[p]!=c[q])s+=a[q];
			a[p]-=a[q];
			q--;
		}
	}
	cout<<s;
	return 0;
}
