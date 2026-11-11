#include<bits/stdc++.h>
using namespace std;
int a[10005];
char c[10005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cmt=0,cnt=0,h=0;
	char q,w;
	cin>>n;
	int b=n/2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=b;i++)
	{
		q=c[i];
		w=c[n-i+1];
		if(q!=w)
		{
			cnt++;
			h+=a[i];
		}
	}
	cout<<cnt*h;
	return 0;
}
