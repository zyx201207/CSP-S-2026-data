#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500007]{};

long long ans=0;

int main()
{
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		
		cin>>a[i];
		
	}
	
	sort(a+1, a+n+1);
	
	long long cnt=1;
	long long now=0;
	ans=1;
	
	int l=1;
	long long shu=a[1];
	
	for(int r=2;r<=n;r++)
	{
		
		long long cha=a[r]-a[r-1];
		
		//cout<<r<<" "<<now<<" "<<cnt<<" "<<cha<<endl;
		
		if(now+cnt*cha<=m)
		{
			
			//cout<<"ans1"<<endl;
			
			now+=cnt*cha;
			cnt++;
			ans=max(ans, cnt);
			shu=a[r];
			
		}
		else
		{
			
			//cout<<"ans2"<<endl;
			
			while(now+cnt*cha>m)
			{
				
				now-=(shu-a[l]);
				l++;
				cnt--;
				
			}
			
			now+=cnt*cha;
			cnt++;
			ans=max(ans, cnt);
			shu=a[r];
			
		}
		
		//cout<<r<<" "<<cnt<<endl;
		
	}
	
	cout<<ans;
	
	return 0;
	
}
