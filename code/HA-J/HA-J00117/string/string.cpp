#include <bits/stdc++.h>
using namespace std;
#define ld long long
struct ic
{
	ld a;
	char c;
};
ic arr[100005];
int main(int argc, char** argv)
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ld n,k=0;
	cin>>n;
	for(ld i=0;i<n;i++)
	{
		cin>>arr[i].a>>arr[i].c;
		if(i<n/2)
		{
			k+=arr[i].a;
		}
	}
	ld s=0,k1=0;
	for(ld i=0,j=n-1;i<j;)
	{
		if(arr[i].c==arr[j].c)
		{
			if(arr[i].a<arr[j].a)
			{
				k1=arr[j].a+k1;
				arr[j].a=arr[j].a-arr[i].a;
				i++;
				continue;
			}
			else if(arr[i].a==arr[j].a)
			{
				j--;
				i++;
				k1=arr[i].a+k1;
				continue;
			}
			else
			{
				k1=arr[i].a+k1;
				arr[i].a=arr[i].a-arr[j].a;
				j--;
				continue;
			}
		}
		else
		{
			if(arr[i].a<arr[j].a)
			{
				s=arr[i].a+s;
				k1=arr[j].a+k1;
				arr[j].a=arr[j].a-arr[i].a;
				i++;
				continue;
			}
			else if(arr[i].a==arr[j].a)
			{
				j--;
				i++;
				k1=arr[i].a+k1;
				s+=arr[i].a;
				continue;
			}
			else
			{
				s=arr[j].a+s;
				k1=arr[i].a+k1;
				arr[i].a=arr[i].a-arr[j].a;
				j--;
				continue;
			}
		}
	}
	cout<<s;
	return 0;
}
