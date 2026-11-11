#include<bits/stdc++.h>
using namespace std;
long long int n,r,l,ans;
struct tt
{
	char zf;
	int num;
} a[1010000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].zf;
	}
	r=1;
	l=n;
	while(r<=l)
	{
		
		if(a[r].zf==a[l].zf)
		{
			if(a[r].num>a[l].num)
			{
				a[r].num-=a[l].num;l--;
			}else if(a[r].num<a[l].num)
			{
				a[l].num-=a[r].num;r++;
			}else {
				l--;r++;
			}
		}else
		{
			if(a[r].num>a[l].num)
			{
				ans+=a[l].num;a[r].num-=a[l].num;l--;
			}else if(a[r].num<a[l].num)
			{
				ans+=a[r].num;a[l].num-=a[r].num;r++;
			}
			else{
				ans+=a[r].num;r++;l--;
			}
		}
		
	}
	cout<<ans;
	return 0;
 } 
