#include<bits/stdc++.h>
using namespace std;
int num[20010];
char c[20010];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>c[i];
	}
	int l=1,r=n-l+1;
	while(l<r)
	{
//		cout<<"c[i]="<<c[l]<<" c[r]="<<c[r]<<endl;
		if(c[l]==c[r])
		{
			
			if(num[l]>num[r])
			{
				num[l]-=num[r];
				r--;
			}
			else if(num[l]<num[r])
			{
				num[r]-=num[l];
				l++;
			}
			else
			{
				l++;r--;
			}
//			cout<<"l="<<l<<" r="<<r<<endl;
		}
		else
		{
			if(num[l]>num[r])
			{
				ans+=num[r];
				num[l]-=num[r];
				r--;
			}
			else if(num[l]<num[r])
			{
				ans+=num[l];
				num[r]-=num[l];
				l++;
			}
			else
			{
				ans+=num[l];
				num[l]=0;
				num[r]=0;
				l++;
				r--;
			}
//			cout<<"l="<<l<<" r="<<r<<endl;
//			cout<<"ans"<<ans<<endl;
		}
		
	}
	cout<<ans;
	return 0;
}
