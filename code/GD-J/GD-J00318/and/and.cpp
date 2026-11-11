#include<bits/stdc++.h>
using namespace std;
int n,m,ans,ind,num[35];
vector<int>b[35];
bool vis[200005];
int can[200005];
bool check(int x)
{
	bool flag=false;
	int sum=0,cnt=0;
	
	for(int i = 31;i>=0;i--)
	{
		
		if(num[i]<m)continue;
		sum+=(int)pow(2,i);
		
		if(!flag)
		{
			for(int j = 1;j <= b[i].size();j++)
			{
				can[b[i][j-1]]=1;//cout <<"here"<<j<<endl;
			}
			flag=1;
		}
		else
		{
			cnt=0;
			for(int j = 1;j <= b[i].size();j++)
			{
				can[b[i][j-1]]=2;
			}
			for(int j = 1;j <= n;j++)
			{
				if(can[j]==2)cnt++;
			}
			if(cnt>=m)
			{
				if(sum>=x&&cnt==m)return true;
				for(int j = 1;j <= n;j++)
				{
					if(can[j]<2)can[j]=0;
					else can[j]=1;
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin >>n>>m;
	for(int i = 1;i <=n;i++)
	{
		int x,idx=0;
		cin >>x;
		while(x>0)
		{
			if(x%2==1){
				b[idx].push_back(i);
				num[idx]++;
			}
			
			idx++;
			x/=2;
		}
	}
	
	int l=0,r=0;
	for(int i = 31;i>=0;i--)
	{
		if(num[i]>=m)r+=(int)pow(2,i);
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout <<ans;
	return 0;
}
