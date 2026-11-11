#include<bits/stdc++.h>
using namespace std;
int q,w;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>q>>w;
	cin>>a[1];
	long long e=a[1];
	for(int i=2;i<=q;i++)
	{
		cin>>a[i];
		e&=a[i];
	}
	sort(a+1,a+1+q);
	if(w==1)
	{
		cout<<a[q]<<endl;
		return 0;
	}
	if(w==2)
	{
		cout<<a[q-2]-2<<endl;
		return 0;
	}
	if(w==q)
	{
		cout<<e<<endl;
		return 0;
	}
	long long r=a[q];
	for(int i=q-1,l=1;l<w;l++,i--)
	{
		r&=a[i];
	}
	cout<<r<<endl;
}
