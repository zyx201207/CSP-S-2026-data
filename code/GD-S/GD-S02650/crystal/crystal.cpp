#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "crystal"
int n,m,a[500010],maxx=-1,num,v;
bool p,A=true,B=true;
void Aa()
{
	num=1;
	int l=0;
	while(m>0)
	{
		l++;
		m-=l;
		if(m<0)
		{
			cout<<num;
			p=true;
			break;
		}
		else if(m==0)
		{
			num++;
			cout<<num;
			p=true;
			break;
		}
		else
		{
			num++;
		}
		m-=l;
		if(m<0)
		{
			cout<<num;
			p=true;
			break;
		}
		else if(m==0)
		{
			num++;
			cout<<num;
			p=true;
			break;
		}
		else
		{
			num++;
		}
	}
	if(!p)
	{
		cout<<num;
	}
}
void Bb()
{
	num=1;
	int l=0;
	while(m>0)
	{
		l+=v;
		m-=l;
		if(m<0)
		{
			cout<<num;
			p=true;
			break;
		}
		else if(m==0)
		{
			num++;
			cout<<num;
			p=true;
			break;
		}
		else
		{
			num++;
		}
		m-=l;
		if(m<0)
		{
			cout<<num;
			p=true;
			break;
		}
		else if(m==0)
		{
			num++;
			cout<<num;
			p=true;
			break;
		}
		else
		{
			num++;
		}
	}
	if(!p)
	{
		cout<<num;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i && A)
		{
			A=false;
		}
		if(i==2)
		{
			v=a[i]-a[i-1];
		}
		if(i>=3 && !(a[i]-a[i-1]==v) && B)
		{
			B=false;
		}
	}
	p=false;
	if(A)
	{
		Aa();
		return 0;
	}
	if(B)
	{
		Bb();
		return 0;
	}
	sort(a+1,a+n+1);
	num=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<endl;
		int sum=0,l1=i-1,r1=i+1,num=0;
		while(sum<=m)
		{
			if(l1>=1 && r1<=n)
			{
				if(abs(a[i]-a[l1])>abs(a[r1]-a[i]))
				{
					sum+=abs(a[r1]-a[i]);
					if(sum<=m)
					{
						num++;
					}
					else
					{
						break;
					}
					r1++;
				}
				else
				{
					sum+=abs(a[i]-a[l1]);
					if(sum<=m)
					{
						num++;
					}
					else
					{
						break;
					}
					l1--;
				}
			}
			else if(l1<1 && r1<=n)
			{
				sum+=abs(a[r1]-a[i]);
				if(sum<=m)
				{
					num++;
				}
				else
				{
					break;
				}
				r1++;
			}
			else if(l1>=1 && r1>n)
			{
				sum+=abs(a[i]-a[l1]);
				if(sum<=m)
				{
					num++;
				}
				else
				{
					break;
				}
				l1--;
			}
			else
			{
//				cout<<l1<<" "<<r1<<endl;
//				cout<<"jkl"<<endl;
				cout<<num;
				p=true;
				break;
			}
//			cout<<l1<<" "<<r1<<" "<<sum<<endl;
		}
		if(p)
		{
			break;
		}
		maxx=max(num,maxx);
//		cout<<num<<endl;
//		cout<<endl;
	}
	if(!p)
	{	
		cout<<maxx+1;
	}
	return 0;
} 
