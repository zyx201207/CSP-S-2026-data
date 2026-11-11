#include<iostream>
#include<algorithm>
#define int long long 
using namespace std;
const int MAXN = 500005;
int a[MAXN]; 
int s[MAXN];
int n,m;
bool check(int x,int tot)
{
	int beg = x,en = tot-1;
	int tot_sum = a[tot]*(en-beg+1);
	int x_sum = s[en]-s[beg-1];
	//cout<<tot<<' '<<beg<<' '<<en<<' '<<tot_sum<<' '<<x_sum<<endl;
	return (tot_sum-x_sum <= m);	
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
		s[i] = a[i]+s[i-1];
	int mx = 0;
	for(int i = 1;i <= n;i++)
	{
		//cout<<i<<':'<<endl;
		int l = 1,r = i-1;
		int mm = i;
		while(l < r)
		{
			int mid = l+(r-l)/2;
			//cout<<l<<' '<<r<<' '<<mid<<endl;
			if(check(mid,i))
			{
				//cout<<"true"<<endl;
				mm = mid;
				r = mid;
			}
			else
			{
				//cout<<"false"<<endl;
				l = mid+1;
			}
		}
		int ans = i-mm+1;
		mx = max(mx,ans);
	}
	cout<<mx;
	/*
	for(int i = 1;i <= n;i++)
	{
		int sum = 0,j = i-1,ans = 1;
		while(sum < m && j >= 0)
		{
			if(a[j] == a[i])
			{
				ans++;
				j--;
				continue;
			}
			if(a[i]-a[j] > m-sum)
			{
				ans++;
				break;
			}
			else
			{
				sum+=a[i]-a[j];
				ans++;
				j--;
			}
		}
		mx = max(mx,ans);
	}
	*/
	return 0;
 } 
