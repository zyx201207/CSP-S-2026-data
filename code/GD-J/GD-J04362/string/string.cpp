#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int n;
string s;
int a[N];
char x[N];
int cnt=0;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>x[i];
		cnt+=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		
		int sum=0;
		while(n>=i&&sum+a[n]<=a[i])
		{
			
			if (x[n]!=x[i])
			{
				ans+=a[n];
				
			}
			sum+=a[n];
			n--;
		}
		if (sum<a[i])
		{
			a[n]-=(a[i]-sum);
			if (x[n]!=x[i])ans+=(a[i]-sum);
			
		}
		
	}
	cout<<ans;
	return 0;
}

