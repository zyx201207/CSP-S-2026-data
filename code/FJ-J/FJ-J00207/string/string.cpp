#include<bits/stdc++.h>
using namespace std;
long long n=0;
char arr[200001];
long long arr1[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int head=1;
	cin>>n;
	int foot=n; 
	for(int i=1;i<=n;i++)
	{
		cin>>arr1[i]>>arr[i];
	}
	int flag=arr1[head];
	long long flag1=0;
	while(head!=foot)
	{
		if(arr1[head]>arr1[foot])
		{
			if(arr[head]!=arr[foot])
			{
				flag1+=arr1[foot];
			}
			flag-=arr1[foot];
			arr1[head]-=arr1[foot];
			foot--;

		}
		else if(arr1[head]==arr[foot])
		{
			if(arr[head]!=arr[foot])
			{
				flag1+=arr1[foot];
			}
			head++;
			foot--;
			flag=arr1[head];

		}
		else
		{
			if(arr[head]!=arr[foot])
			{
				flag1+=arr1[head];
			}
			flag=arr1[foot]-flag;
			head++;

		}
	}
	cout<<flag1;
	return 0;
}




