#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long x;
	char y;
}p[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,mid=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long t;
		cin>>t;
		char s;
		cin>>s;
		p[i].x=t;
		p[i].y=s;
		mid+=t;
		//cout<<mid<<" ";
	}
	
	if(mid%2!=0)
	{
		mid/=2;
		mid++;
	}
	else
	{
		mid/=2;
	}
	int cnt=0;
	
		long long ans=0;
		for(int l=1,r=n;r>l;)
		{
			//cout<<"114514";
			if(p[l].y==p[r].y)
			{
				//cout<<"1919810";
				if(cnt+min(p[l].x,p[r].x)<=mid)//aa bb c
				{
					cnt+=min(p[l].x,p[r].x);
					if(p[l].x>p[r].x)
					{
						r--;
						p[l].x-=p[r].x;	
					}
					else if(p[l].x<p[r].x)
					{
						l++;
						p[r].x-=p[l].x;
					}
					else
					{
						l++;
						r--;
					}
					
				}
				else
				{
					cout<<ans;
					return 0;
				}
			}
			else
			{
				//cout<<"114514";
				//cout<<cnt+min(p[l].x,p[r].x)<<" "<<mid<<endl;
				if(cnt+min(p[l].x,p[r].x)<=mid)//aa bb c
				{
					//cout<<"114514";
					cnt+=min(p[l].x,p[r].x);
					if(p[l].x>p[r].x)
					{
						
						r--;
						p[l].x-=p[r].x;	
						ans+=p[r].x;
						
					}
					else if(p[l].x<p[r].x)
					{
						l++;
						p[r].x-=p[l].x;
						ans+=p[l].x;
						//cnt+=min(p[l].x,p[r].x);
					}
					else
					{
						l++;
						r--;
						ans+=p[l].x;
					}
					
				}
				else
				{
					//cout<<"114514";
					cout<<ans;
					return 0;
				}
			}
		}
	cout<<ans;	
}
