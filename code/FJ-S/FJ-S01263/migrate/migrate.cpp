#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int a[500005]={0};
		int t[500005]={0};
		t[0]=-1e9;
		int two[500005][3]={0};
		int cnt=0,ck=0;
		int n,d;
		cin>>n>>d;
		int p=n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			//cout<<a[i]-a[i-1]<<endl;
			if(i>=2&&a[i]-a[i-1]>=d&&p==n) 
			{
				p=i;
			}
		}
		n=p;
		cout<<n<<endl;
		for(int i=1;i<=n-2;i++)
		{
			if(a[i+2]-a[i]<=d&&a[i+1]-a[i]<=d)
			{
				ck++;
				t[ck]=i;
				if(t[ck-1]+1==t[ck])
				{
					cnt++;
					two[cnt][1]=i-1;
					two[cnt][2]=i+2;
				}
			}
		}
		cnt++;
		two[cnt][1]=n;
		long long ans=0;
		int l=abs(two[1][1]-1),r=abs(two[1][2]-two[2][1]);
		for(int i=1;i<cnt;)
		{
			ans+=l*r;
			cout<<ans<<' '<<l<<' '<<r<<endl;
			i++;
			l=r;
			if(two[i-1][2]>=two[i][1]) l=0;
			r=abs(two[i+1][1]-two[i][2]-1);
			cout<<two[i][1]<<' '<<two[i][2]<<endl;
		}
		cout<<ans<<endl;
	}
}
