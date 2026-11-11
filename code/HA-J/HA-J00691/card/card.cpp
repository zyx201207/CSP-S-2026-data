#include<bits/stdc++.h>
using namespace std;

long long arr[100005],que[100005],brr[100005];
long long n,m,front,rear,num;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	long long sum;
	for(long long i=1;i<=n;i++)
	{
		sum=i+1;
		for(long long k=0;k<100005;k++)
		{
			que[k]=0;
		}
		front=rear=0;
		que[rear++]=arr[i];
		while(sum<=n)
		{
			bool flag=true;
			for(long long j=front;j<rear;j++)
			{
				if(que[j]==arr[sum])
				{
					for(long long k=j+1;k<rear;k++)
					{
						que[k]=0;
					}
					rear=j+1;
					flag=false;
					break;
				}
			}
			if(flag==true)
				{
					que[rear++]=arr[sum];
				}
			sum++;
    	} 
			for(long long k=1;k<=m;k++)
			{
				for(long long j=front;j<rear;j++)
				{
					if(que[j]==k)
					brr[k]++;
				}
			}
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<brr[i]<<' ';
	}
	return 0;
}
