#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005];
long long b[200005][35];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=-10;
	for(int i=1;i<=n-k;i++)
	{
		long long sum=0;
		for(int j=i;j<=i+k-1;j++)
		{
			sum=a[j]&a[j+1];
		}
		cnt=max(cnt,sum);
	}
	cout<<cnt;
	return 0;
}
