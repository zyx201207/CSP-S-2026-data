#include <iostream>
#include <string>
using namespace std;
struct s
{
	char c;
	long long num;
};
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	s arr[n+1];
	for (int i=1;i<=n;i++) cin>>arr[i].num>>arr[i].c;
	int l=1,r=n;
	while(l<r)
	{
		if(arr[l].c!=arr[r].c)
		{
			ans+=min(arr[l].num,arr[r].num);
			if(arr[l].num>arr[r].num)
			{
				arr[l].num-=arr[r].num;
				r--;
			}
			else if(arr[l].num<arr[r].num)
			{
				arr[r].num-=arr[l].num;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(arr[l].num>arr[r].num)
			{
				arr[l].num-=arr[r].num;
				r--;
			}
			else if(arr[l].num<arr[r].num)
			{
				arr[r].num-=arr[l].num;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
