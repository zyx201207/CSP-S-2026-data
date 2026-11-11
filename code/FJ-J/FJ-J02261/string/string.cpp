#include<iostream>
#include<cstring>
using namespace std;
using ll=long long;
ll x=1,y=0,x1=0,y1=0,x2,y2,l,s;
struct Edge{
	ll data;
	char ch;
};
Edge a[200000+5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i].data;
		cin>>a[i].ch;
		l+=a[i].data;
	}
	x2=1;y2=n;
	x1=0;y1=0;
	for(ll i=1,j=l;i<j;)
	{
		if(x2==y2)
		{
			break;
		}
		if((a[x2].data-x1)>(a[y2].data-y1))
		{
			ll c=a[y2].data-y1;
			i+=c;j-=c;
			if(a[x2].ch!=a[y2].ch)
			{
				s+=c;
			}
			y2--;
			x1+=c;
			y1=0;
		}
		else if((a[x2].data-x1)<=(a[y2].data-y1))
		{
			ll c=a[x2].data-x1;
			i+=c;j-=c;
			if(a[x2].ch!=a[y2].ch)
			{
				s+=c;
			}
			x2++;
			x1=0;
			y1+=c;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
