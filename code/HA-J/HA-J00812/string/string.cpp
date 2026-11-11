#include<bits/stdc++.h>
using namespace std;

int n;
struct huiwen
	{
		int num;
		char word;
	};
huiwen a[2*100000+2];

bool check()
{
//	string b;int s=0;
//	
//	for(int i=1;i<=n;i++)
//	{
//		s=s+a[i].num;
//	}
//	for(int i=1;i<=s;i++)
//	{
//		
//	}
	
	bool f=true;int count=0;
	if(n%2==0)
	{
		for(int i=n;i>(n/2);i--)
		{
			if(a[i].word!=a[n-i+1].word)
			{
				if(a[i].word<=a[n].word)
				{
					f=false;
				count=count+a[i].num;
				}
				else
				{
						f=false;
				count=count+a[n].num;
				}
				
			}
		}
	}
	else
	{
		for(int i=n;i>(n/2+1);i--)
		{
			if(a[i].word!=a[n-i+1].word)
			{
//				if(a[i].word<=a[n-i+1].word)
//				{
//					f=false;
//				count=count+a[i].num;
//				}
//				else
//				{
//						f=false;
//				count=count+a[n-i+1].num;
//				}
				int all=0,t=1,r=0;
				for(int i=1;i<=n;i++)
				{
					all=all+a[i].num;
				}
				while(r<(all/2+1))
				{
					r=r+a[t].num;
					t++;
				}
				for(int i=n;i>t;i--)
				{
					f=false;
					count=count+a[i].num;
				}

			}
		}

	
		

	}
	
	if(f)
		return true;
	else
		cout<<count;
		return false;
	
	
}


int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].word;		
	}
	if(check())
	{
		cout<<"0";
	}

	
	return 0;
}
