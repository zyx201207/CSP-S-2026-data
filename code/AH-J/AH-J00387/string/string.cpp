#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int x;
	char ch;
};
const int N=2e5+10;
Node a[N];
int s,l,pos,r,j,ans,k;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].ch;
		s+=a[i].x;
	}
	for(int i=1;i<=n;i++)
	{
		if(k+a[i].x>s/2)
		{
			for(int ii=n++;ii>=i+1;ii--)
				a[ii+1]=a[ii];
			a[i+1].ch=a[i].ch;
			a[i+1].x=a[i].x+k-s/2-(s%2);
			a[i].x=s/2-k;
			pos=i;
			break;
		}
		k+=a[i].x;
	}
	j=n;
	for(int i=1;i<=pos;i++)
	{
		l+=a[i].x;
		while(l>=r+a[j].x)
		{
			r+=a[j].x;
			if(a[j].ch!=a[i].ch)ans+=a[j].x;
			j--;
		}
		if(a[j].ch!=a[i].ch)ans+=l-r;
		a[j].x-=l-r;
		r=l;
	}
	cout<<ans<<endl;
	return 0;
}
