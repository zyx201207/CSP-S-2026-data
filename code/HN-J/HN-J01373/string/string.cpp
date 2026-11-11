#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
struct node
{
	int s;
	char b;
}a[200001];
int k;
int p;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i].s>>a[i].b;
    	cnt+=a[i].s;	
	}
	int yu=cnt;
	if(cnt%2)
	{
	    cnt+=1;	
	}
	cnt/=2;
	for(int i=0;i<n;i++)
	{
		k+=a[i].s;
		if(k>=cnt)
		{
			p=i;
			break;
		}
	}
	for(int o=0;o<=p;o++)
	{
		int h=n-o;
		while(a[h].s==0)
		{
			h--;
		}
		if(a[o].b==a[h].b)
		{
			cnt-=min(a[o].s,a[h].s);
		}
		a[o].s-=min(a[o].s,a[h].s);
		a[h].s-=min(a[o].s,a[h].s);
		if(o==p)
		{
			if(yu%2)
			{
				cnt-=a[o].s/2+1;
			}
			cnt-=a[o].s/2;
		}
	    if(a[o].s)
	    {
	    	o--;
		}
		
	}
	cout<<cnt;
    return 0;
}
