#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long dp[N];
long long ans[N]={1};
long long puls[N]={0};
long long n,m;
bool check1(long long l,long long r)
{
	if(puls[r]-puls[l-1]-(a[r]-a[l-1])*(l-1)<=m)
		return 1;
	else
		return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cin.tie(0);
	cin>>n>>m;
	
	
	
	int flag=0,flag1=0;
	long long zan;
	cin>>a[1];
	zan=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		long long check;
		check=a[i]-a[i-1];
//		cout<<"check4 "<<check<<endl;
/*
		if(flag==1&&check!=1)
			flag1=5;
		else if(flag==2&&check==i-1)
			flag1=5;
		else if(check==1)
			flag=1;
		else if(check==i-1) 
			flag=2;
		else
			flag=0;
*/
	}
//	cout<<"check1 "<<flag<<' '<<flag1<<endl;
	//特判13-18测试点 
	/*
	if(flag!=0&&flag1!=5)
	{
		if(flag==1)
		{
			long long sum=0,ans=1,i=1;
			while(sum<m)
			{
				sum+=i*2-1;
				i++;
				ans++;
			}
			cout<<ans;
			return 0;
		}
		else if(flag==2)
		{
			long long sum=0,ans=1,i=2;
			while(sum<m)
			{
				sum+=i*i;
				i++;
				ans++;
			}
			cout<<ans;
			return 0;
		}
	}
	*/
//	cout<<"*";
	//到此为止 
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<endl<<flag;
	for(int i=2;i<=n;i++)
	{
		puls[i]=(a[i]-a[i-1])*(i-1)+puls[i-1]; 
//		cout<<puls[i]<<' ';
	}
//	cout<<'*';
	long long l,r,less=1;
	for(int i=2;i<=n;i++)
	{
		
		if(a[i]==a[i-1])
		{
			ans[i]=ans[i-1]+1;
			continue;
		}
		r=i; 
		l=less;
//		cout<<"check1 "<<l<<' '<<r<<endl;
//		cout<<i<<endl;
		long long cha=a[i]-a[i-1]; 
		while(l<r)
		{
			long long mid=l+(r-l)/2;
//			cout<<"check3 "<<l<<' '<<r<<' '<<mid<<' '<<check1(l,r)<<endl; 
			if(check1(mid,i))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
//		cout<<"check2 "<<l<<' '<<r<<endl;
		less=l;
		ans[i]=i-l+1;
//		cout<<"check10 "<<ans[i]<<endl; 
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n]; 
	return 0;
}
/*
10 11
1 2 3 4 5 6 7 8 9 10



10 46
1 2 4  7 11  16 22 29 37 46



7 7 
-3 -1 2 7 8 8 9




5 5
1 2 4 8 9


	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	RP++;
	AK IOI!
	5:43 终于写完第一题了QWQ!!! 

*/
