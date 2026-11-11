#include<bits/stdc++.h>
using namespace std;
long long a,b[1000005],d=0,sum=0,x,y;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>b[i];
		cin>>s[i];
	}
	x=a-1;
	y=0;
	for(int i=0;i<9;i++)
	{
		if(x==y || y-x==1)
			break;
		if(s[y]!=s[x])
		{
			sum+=min(b[i],b[x]);
		}
		if(b[x]>b[i])
		{
			b[x]-=b[i];
			y+=1;
		}
		else if(b[x]==b[y])
		{
			x-=1;
			y+=1;
		}
		else{
			b[i]-=b[x];
			x-=1;
		}	
	} 
	cout<<sum;
	return 0;
 } 
