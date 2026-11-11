#include<iostream>
using namespace std;
int a[200005];
char b[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long ans=0;
	int L=1,R=n;
	int Lz=0,Rz=0;
	while(L<R)
	{
		if(b[L]==b[R])
		{
			int now1=a[L]-Lz;
			int now2=a[R]-Rz;
			if(now1<now2)
			{
				L++;
				Lz=0;
				Rz+=now1;
			}
			if(now1==now2)
			{
				L++;
				R--;
				Lz=0;
				Rz=0;
			}
			if(now1>now2)
			{
				R--;
				Rz=0;
				Lz+=now2;
			}
		}
		else
		{
			int now1=a[L]-Lz;
			int now2=a[R]-Rz;
			if(now1<now2)
			{
				L++;
				Lz=0;
				Rz+=now1;
				ans+=now1;
			}
			if(now1==now2)
			{
				L++;
				R--;
				Rz=0;
				Lz=0;
				ans+=now1;
			}
			if(now1>now2)
			{
				R--;
				Rz=0;
				Lz+=now2;
				ans+=now2;
			}
		}
	}
	cout<<ans;
}
