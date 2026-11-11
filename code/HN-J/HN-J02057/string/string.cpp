#include<bits/stdc++.h>
using namespace std;

long long m[200001];
long long a=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int n;
	cin>>n;
	char m2[200001]; 
	for(int i=0;i<n;i++){
		cin>>m[i]>>m2[i];	
	}
	
	int x=0,y=n-1,bug=0;
	while(x!=y)
	{
		a=m[y]-m[x];
		if(a==0)
		{
			if(m2[x]!=m2[y])
			{
				ans+=m[x];
			}
			y--;
			x++;
		}
		if(a>0)
		{
			if(m2[x]!=m2[y])
			{
				ans+=m[x];
			}
			m[y]-=m[x];
			x++;
		}
		if(a<0)
		{
			if(m2[x]!=m2[y])
			{
				ans+=m[y];
			}
			m[x]-=m[y];
			y--;
		}
	}
	cout<<ans;
	
}
