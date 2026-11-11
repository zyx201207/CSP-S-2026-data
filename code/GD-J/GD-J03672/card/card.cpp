#include <iostream>
#include <cstring>
using namespace std;
int l[500005],a[500005],s[500005],an[300005],sq,n,m;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		sq=0;
		memset(l,0,sizeof(l));
		for (int j=i;j<=n;j++)
		{
			if (l[a[j]]&&l[a[j]]<=sq)
				sq=l[a[j]];
			else
				s[++sq]=a[j],l[a[j]]=sq;	
		}
		for (int j=1;j<=sq;j++)
		{
			an[s[j]]++;
		}
	}
	for (int i=1;i<=m;i++)
		cout<<an[i]<<' ';
	return 0;
}
