#include<bits/stdc++.h>
using namespace std;
int n;
long long a,size,s,lef,rig;
char c,mid;
string mu;
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
		mu+=c;
		}
		size+=a;
	}
	mid=(size+1)/2;
	
	if(size%2!=0)
	{
		lef=rig=mid;
		
	}
	else 
	{
		lef=mid;
		rig=mid+1;
		cout<<lef<<rig;
	}
	while(lef!=0)
	{
		if(mu[lef-1]!=mu[rig-1])
		{
			s++;
		}
		lef--;
		rig++;
	}
	cout<<s;
return 0;
} 
