#include<bits/stdc++.h>
using namespace std;

long long n,sum=1;
char brr[1000000000];
struct logic
{
	long long count;
	char zm;
};
logic arr[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>arr[i].count>>arr[i].zm;
	}
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=arr[i].count;j++)
    	{
    		brr[sum++]=arr[i].zm;
		}
	}
	sum--;
	long long num=0;
	if(sum%2==0)
	{
		for(int i=sum/2,j=sum/2+1;i>=1,j<=sum;i--,j++)
		{
			if(brr[i]!=brr[j])
			{
				num++;
			}
		}
	}
	else if(sum%2==1)
	{
		for(int i=sum/2,j=sum/2+2;i>=1,j<=sum;i--,j++)
		{
			if(brr[i]!=brr[j])
			{
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
