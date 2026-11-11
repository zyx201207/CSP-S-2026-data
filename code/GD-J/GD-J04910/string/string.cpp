#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,q,w,e;
char c[200005];
int main()
{
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	q=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n/2;i++)
	{
		w=0;
		while(w<a[i])
		{
			if(w+a[q]<=a[i]&&c[i]!=c[q])
			{
				e+=a[q];
				w+=a[q];
				q--;
				break;
			}
			else if(c[i]!=c[q])
			{
				e+=a[i]-w;
				
			}
			w+=a[q];
		}
	}
	cout<<e;
}
