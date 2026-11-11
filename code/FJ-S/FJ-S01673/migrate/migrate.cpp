#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5006,M=2e6+6;
int q[N],h[N],a[N],jl[N],qz[N],b[N],e[M];
bool pd[N];
int suan(int n,int d)
{
	int ans=0;
	
	for(int i=0;i<=n;i++) q[i]=h[i]=0;
	
	int zz=1;
	for(int i=1;i<=n;i++)
	{
		while(a[i]-a[zz]>d)
		{
			//cout<<zz<<endl;
			zz++;
		}
		q[i]=zz;
	}
	zz=n;
	for(int i=n;i>=1;i--)
	{
		while(a[zz]-a[i]>d)
		{
			//cout<<zz<<endl;
			zz--;
		}
		h[i]=zz;
	}
	
//	cout<<"666"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) pd[j]=0,jl[j]=0,qz[j]=0;
		for(int j=i;j!=n;j=h[j])
		{
			pd[j]=1;
		}
		pd[n]=1;
		for(int j=1;j<=n;j++) qz[j]=qz[j-1]+pd[j];
		for(int j=i+1;j<=n;j++)
		{
			if(q[j]<=i) continue;
			if(qz[j-1]-qz[q[j]]==0)
			{
				jl[j]=jl[q[j]];
				continue;
			}
			if(qz[j-1]-qz[q[j]]==1&&pd[q[j]+1]==1)
			{
				jl[j]=jl[q[j]]+1;
				continue;
			}
			jl[j]=2;
		}
//		if(i==1){
//cout<<i<<endl;
//		for(int j=1;j<=n;j++) cout<<jl[j]<<' ';
//		cout<<endl;
//}
		for(int j=i+1;j<=n;j++) if(jl[j]==1)
		{
			ans++;
		}
	}
	return ans;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12)
	{
		while(t--)
		{
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>e[i];
			if(n==1)
			{
				cout<<"0\n";
				continue;
			}
			int js=d/(e[2]-e[1]);
			if(js<=1) cout<<"0\n";
			else cout<<max(n-2*js+1,0ll)<<'\n';
		}
		return 0;
	}
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>b[i];
		if(n==1)
		{
			cout<<"0\n";
			continue;
		}
		int l=1;
		b[n+1]=8e18;
		for(int i=2;i<=n+1;i++)
		{
			if(b[i]-b[i-1]>d)
			{
				int cnt=0;
				for(int j=l;j<i;j++) a[++cnt]=b[j];
				ans+=suan(cnt,d);
				l=i;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

