#include<bits/stdc++.h>
using namespace std;
long long a[500011],ctrltime,c[5000011];
int n,ans;
bool cmp(long long a,long long b)
{
	return a<b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>ctrltime;
	for(int i=0;i<n;i++) cin>>a[i];
	a[500010]=1e15;
	long long minn=500010;
	sort(a,a+n,cmp);
/*	for(int i=0;i<n;i++)
	{
		long long temp=0;
		for(int j=0;j<i;j++) temp+=abs(a[i]-a[j]);
		
//		minn=(min(a[minn],temp)==temp ? i:minn);
	}*/
	
	for(int i=0;i<n;i++)
	{
		memset(c,0,sizeof(c));
		for(int j=0;j<i;j++) c[j]=abs(a[i]-a[j]);
		sort(c,c+i+1,cmp);
		int sum=1;
		for(int x=0;x<i;x++)
		{
			if(ctrltime<c[x]) break;
			ctrltime-=c[x];
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
