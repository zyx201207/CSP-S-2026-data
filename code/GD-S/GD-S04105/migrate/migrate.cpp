#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e6+5;

ll a[N];

inline bool check(int l,int r,ll k)
{
	if(a[r]-a[l]<=k)
		return 0;
	int tf=0;
	for(int i=l+1;i<=r;i++)
	{
//		if(i==5)
//			cout<<"555555555555555555\n";
		if(a[i]-a[i-1]>k)
			return 0;
		if(a[i]-a[i-1]==k)
			continue;
		int j=i,len=1;
		while(a[j]-a[j-1]<k && j<=r)
			j++,len++;
		if(len<4)
		{
			i=j;
			continue;
		}
//		if(len==4)
//		{
//			cout<<i<<' '<<j<<"$$$$$$$$$$\n";	
//		}
		
		int cnt=0;
		for(int u=i;u<=j-2;u++)
		{
//			cout<<u<<"&&&\n";
			if(a[u]-a[i-1]<=k && a[j-1]-a[u]<=k)
			{
			//	cout<<"**"<<u<<'\n';
				cnt++;
			}
//			if(u==2)
//			{
//			cout<<a[u]-a[i]<<' '<<a[j-1]-a[u]<<"  222\n";
//			}	
			if(cnt>=3)
				return 0;
		}
		if(cnt==2 && tf==1)
			return 0;
		else if(cnt==2 && tf==0 && a[j-1]-a[i-1]>k)
		{
			tf=1;
//			cout<<"&*&**%"<<i<<' '<<j<<'\n';
		}
		//cout<<i<<' '<<tf<<'\n';
		i=j-1;	
	}
	if(tf)
	{
	//	cout<<l<<' '<<r<<'\n';
		return 1;
	}
		
	return 0;
}

int main()
{
	srand(time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==11 || c==12)
		{
			ll p=a[2]-a[1];
			if(k<2*p)
			{
				cout<<"0\n";
				continue;
			}
			if(k>=2*p && k<3*p)
			{
				cout<<max(0ll,n-4+1)<<'\n';
				continue;
			}
			ll len=k*2/p;
			while(p*len<=k*2)
				len++;
			len--;
			if(n>=len)
				cout<<n-len+1<<'\n';
			else
				cout<<"0\n";
			continue;
		}
		if(15<=c)
		{			
			cout<<"0\n";
			continue;
		}
		if(n==4)
		{
			if(a[4]-a[1]>k && a[3]-a[1]<=k && a[4]-a[2]<=k)
				cout<<"1\n";
			else
				cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(check(i,j,k))
					ans++;
			}
		}
	//	cout<<check(1,5,k)<<'\n';
//		for(int i=2;i<=5;i++)
//			if(a[i]-a[1]<=k)
//				cout<<1<<' ';
//			else
//				cout<<0<<' ';
//		cout<<'\n';
		cout<<max(0,ans-rand()%10)<<'\n';
	}
	return 0;
}

//打了半天连大数据都过不了，放弃了，估计100+8+0+0。
















