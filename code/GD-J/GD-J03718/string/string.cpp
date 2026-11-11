#include<iostream>
#include<algorithm>
using namespace std;
struct note{
	long long x=0;
	char bit;
}d[200005];
long long sum=0,sum1=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i].x>>d[i].bit;
		d[i].x+=d[i-1].x;
	}
	long long cnt=d[n].x;
	long long mid=cnt/2+cnt%2,midi;
	for(int i=1;i<=n;i++)
	{
		if(mid<d[i].x)
		{
			midi=i;
			break;
		}
	}
	int j=n-1;
	for(int i=1;i<=midi;i++)
	{
		
		while(d[i].x>cnt-d[j].x)
		{
			if(d[j+1].bit!=d[i].bit)
			{
				sum+=d[j+1].x-d[j].x;
			}
			j--;
		}
		if(cnt-d[j].x!=d[i].x){
			if(d[j+1].bit!=d[i].bit)
			{
				sum+=d[i].x-(cnt-d[j+1].x);
			}
		}
	}
	int i=1;
	for(int j=n;j>midi;j--)
	{
		while(cnt-d[j].x>d[i].x)
		{
			if(d[i].bit!=d[j].bit)
			{
				sum1+=d[i].x;
			}
			i++;
		}
		if(d[j].x!=d[i-1].x){
			if(d[i].bit!=d[j].bit)
			{
				sum1+=cnt-d[j].x-d[i-1].x;
			}
		}
	}
	cout<<min(sum1,sum);
	return 0;
}
/*
2
2 a
3 a
6 
1000000000 a 
1000000000 a 
1000000000 a 
1000000000 b 
1000000000 b 
1000000000 b

*/
