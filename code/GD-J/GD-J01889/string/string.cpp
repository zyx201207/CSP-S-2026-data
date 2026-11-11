#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long l=1,r=n;
	long long total=0;
	while(l<r)
	{
//		cout<<l<<" "<<r<<"\n";
		long long minn=min(a[l],a[r]);
		a[l]-=minn;
		a[r]-=minn;
		int temp1=a[l];
		int temp2=a[r];
		if(c[l]!=c[r])total+=minn;
		if(temp1==0)l++;
		if(temp2==0)r--;
	}
	cout<<total;
	return 0;
}

