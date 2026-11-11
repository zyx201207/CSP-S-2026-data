#include<bits/stdc++.h>
using namespace std;
int n;
long long l=0,a[200001],f,e,w=0;
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	f=1;
	e=n;
	while(f<e)
	{
		if(a[f]<1)	f++;
		if(a[e]<1)	e--;
		if(c[f]!=c[e])	w+=min(a[f],a[e]);
		a[f]-=min(a[f],a[e]);
		a[e]-=min(a[f],a[e]);
	}
	cout<<w;
	return 0;
}
