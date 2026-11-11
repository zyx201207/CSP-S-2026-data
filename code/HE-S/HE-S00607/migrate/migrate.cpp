#include <bits/stdc++.h>
using namespace std;

const int N=2*1e6+10;
int c,t;
long long arr[N];
long long pre_[N];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>c>>t;
	while(t--)
	{
		int n=0;
		long long sum_=0;
		long long d=0;
		bool flag=true;
		
		long long cha=0;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
		{
			cin>>arr[i];
			if(i==1) continue;
			else if(i==2) cha=arr[i]-arr[i-1];
			else if(arr[i]-arr[i-1]!=cha) flag=false;
			pre_[i-1]=arr[i]-arr[i-1];
		}
		
		for(int i=1;i<n;i++) 
		{
			if(pre_[i]<d) pre_[i]+=pre_[i-1];
			else n=i;
		}
		if(flag)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					if(((j-i)*cha)/d!=0&&((j-i)*cha)%d!=0&&((j-i)*cha+d-1)/d<((j-i)*cha+d-2)/(d-1))
					{
						sum_++;
					}
				    
				}
			}
			cout<<sum_<<'\n';
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					if((pre_[j-1]-pre_[i-1])/d!=0&&(pre_[j-1]-pre_[i-1])%d!=0&&(pre_[j-1]-pre_[i-1]+d-1)/d<(pre_[j-1]-pre_[i-1]+d-2)/(d-1))
					{
						sum_++;
					 } 
				}
			}
			cout<<sum_<<'\n';
		}
	}
	
return 0;}
