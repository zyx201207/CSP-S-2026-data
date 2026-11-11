#include<bits/stdc++.h>
using namespace std;
struct sub{
	int num;
	int time;
};
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	int we,ew;
	cin>>we;
	sub x[we];
	for(int i=0;i<we;i++)cin>>x[i].num>>x[i].time;
	cin>>ew;
	sub y[ew];
	for(int i=0;i<ew;i++)cin>>y[i].num>>y[i].time;
	for(int oo=0;oo<q;oo++)
	{
		int l,r;
		cin>>l>>r;
		int ans=0;
		ans+=a[l]+a[r];
		for(int i=l;i<r;i++)
		{
			ans+=x[i].time;
		}
		cout<<ans;
	}
	return 0; 
}
