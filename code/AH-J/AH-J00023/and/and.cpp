#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,Max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=m;
	for(int i=1;i<=n&&r<=n;i++)
	{
		long long s=a[l];
		for(int j=l+1;j<=r;j++)
		{
			s^=a[i];
		}
		Max=max(Max,s);
	}
	cout<<Max;
	return 0;
}
