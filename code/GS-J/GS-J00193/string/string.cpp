#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string cd,r;
long long nd=0,s=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>r;
		for(int q=1;q<=a[i];q++)
		cd+=r;
		s+=a[i];
	}
	for(int i=0;i<=(s-1)/2;i++)
	if(cd[i]!=cd[(s-1)-i])
	nd++;
	cout<<nd;
	return 0;
}
