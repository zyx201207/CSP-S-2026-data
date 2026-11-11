#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],d[500005],q[500005],c,num;
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n-1;i++)cin>>a[i];
	sort(a+0,a+n);
	for(int i=1;i<=n-1;i++)d[i]=a[i]-a[i-1];
	for(int i=n-1;i>=1;i--)q[i]=q[i+1]+d[i];
	int i=1,j=1;
	num=q[1]-q[2];
	while(1)
	{
		if(num<=m&&j<n-1)
		{
			num=num+q[j+1]*(j-i+1);
			j++;
			num=num+q[j]-q[j+1]*(j-i+1);
		}
		else if(i<n-1)
		{
			num=num+q[j+1]*(j-i+1);
			i++;
			num=num-q[i-1]-q[j+1]*(j-i+1);
		}
		else break;
		ans=max(ans,j-i+1);
		//cout<<i<<" "<<j<<endl;
	}
	//for(int i=0;i<=n-1;i++)cout<<q[i]<<' ';
	cout<<ans;
	return 0;
}
