#include<bits/stdc++.h>
using namespace std;
long long int n,w,ans3,j,a[1000100],b[1000100],t,l,r,ans1,ans2=-1;
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	//freopen("crystal3.in","r",stdin);
	//freopen("crystal3.an","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	t=n/2;
	if(a[1]==a[n])
	
	{cout<<n;
	return 0;
	}
	while(t>0&&t<=n)
	{	
		if(b[t]==-1&&b[t-1]==1) 
		{
			cout<<j; break;
		}
		if(b[t]==1&&b[t-1]==-1) 
		{
			cout<<j+1; break;
		}if(t==n)
		{
			if(b[t]==1)
			{
				cout<<n;
				return 0;
			}
		}
		ans1=0;
		for(j=1;j<t;j++)
	{
		ans1+=(a[t]-a[j]);
		if(ans1>w)
		{
			
			ans1=-1;
			b[t]=-1;
			t=t/2;
		
			break;
		}
	}
	ans2=max(ans2,ans1);
		if(w>=ans1)
		{	b[t]=1;
		if((n-t)/2>=1)
			t+=((n-t)/2);
			else t+=1;
			
			
		}
	}


	return 0;
 } 
