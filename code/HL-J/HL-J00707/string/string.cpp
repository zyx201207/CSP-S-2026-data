#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=200010;

int n;
int a[N];

string s;
char cc[N];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	
	cin >> n;
	
	int sum=0;
	
	a[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		char c;
		
		cin >> a[i] >> c;
		
		sum+=a[i];
		
		for(int j=sum-a[i]+1;j<=sum;j++)
		{
			s[j]=c;
			cc[j]=s[j];
		}
	}
	
	if(sum%2!=0)
	{
//		cout << "sum=" << sum << "\n";
		
		int cnt1=0,cnt2=0;
		int ans=0;
		
		for(int i=1;i<(sum+1)/2;i++)
		{
			if(cc[i]!=cc[sum+1-i])
			{
				cnt1++;
			}
		}
		
		for(int i=sum;i>(sum+1)/2;i--)
		{
			if(cc[i]!=cc[sum+1-i])
			{
				cnt2++;
			}
		}
		
		ans=min(cnt1,cnt2);
		
		cout << ans << "\n";
	}
	
	else if(sum%2==0)
	{
//		cout << "sum=" << sum << "\n";
		
		int cnt1=0,cnt2=0;
		int ans=0;
		
		for(int i=1;i<=sum/2;i++)
		{
			if(cc[i]!=cc[sum+1-i])
			{
				cnt1++;
			}
		}
		
		for(int i=sum;i>sum/2;i--)
		{
			if(cc[i]!=cc[sum+1-i])
			{
				cnt2++;
			}
		}
		
		ans=min(cnt1,cnt2);
		
		cout << ans << "\n";
	}
	return 0;
}