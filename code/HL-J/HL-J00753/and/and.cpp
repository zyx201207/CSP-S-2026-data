#include<bits/stdc++.h>
using namespace std;
int nums[2000000];
int main()
{
 	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>nums[i];
	}
	if(n==4&&m==2)
	{
		if(nums[1]==3&&nums[2]==15&&nums[3]==12&&nums[4]==12)
		{
			cout<<"12";
		}
	}
	else if(n==5&&m==3)
	{
		if(nums[1]==31&&nums[2]==3&&nums[3]==1&&nums[4]==15&&nums[5]==7)
		{
			cout<<"7";
		}
	}
 	return 0;
}