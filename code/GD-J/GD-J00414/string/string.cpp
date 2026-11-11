#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,sum,ans;
struct asd
{
	int x;
	char c;
}a[N];
asd b[N],c[N];
int bt,ct; 
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	for(int qh=0,i=0;i<n;i++)
	{
		if(qh<=sum/2)
		{
			if(sum/2-qh>=a[i].x)
				b[bt++]=a[i];
			else
			{
				if(sum/2-qh!=0)
					b[bt++]={sum/2-qh,a[i].c};
				if(sum%2==0) 	
				    c[ct++]={qh+a[i].x-sum/2,a[i].c};
				else
				    c[ct++]={qh+a[i].x-(sum+1)/2,a[i].c};
			}
		}
		else
			c[ct++]=a[i];
		qh+=a[i].x;
	}	
	for(int i=0,j=ct-1;i<bt;)
	{
		while(1)
		{
			if(b[i].x>=c[j].x)
			{
				b[i].x-=c[j].x;
				ans+=(b[i].c==c[j].c?0:c[j].x);
				j--;
			}
			else
			{
				c[j].x-=b[i].x;
				ans+=(b[i].c==c[j].c?0:b[i].x);
				i++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
