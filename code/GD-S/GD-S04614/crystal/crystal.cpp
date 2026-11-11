#include<bits/stdc++.h>
using namespace std;
long long a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	int n;
	cin>>n;
	long long m;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long p=m;
	long long ans=0,ans1=0;
	for(int i=a[n];i>=a[1];i--)//基准值 
	{
		m=p;
		ans1=0;
		for(int j=n;j>=1;j--)//遍历数组 
		{
			if(ans>(j+ans1))
				break;
			if(a[j]>i)
				continue;
			if(i-a[j]<=m) {
				m-= i-a[j];
				ans1++;
			}else
			break;
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
 }

