#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N=1e6+10;
ll c,n,d,t,a[N],b[N];
ll st[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;//问提所在 
//	cout<<c<<" "<<t<<" ";
		for(int i=1;i<=n;i++) st[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
//		for(int i=1,j;i<n-2;i++)
//		{
//			j=i+2;
//			if(st[j]) continue;
//			if(b[i]+b[i+1]+b[j]>d) continue;
//			
//		}
		for(int i=1;i<=n;i++)
		{
			int j=i+1;
			while(a[j]-a[i]<=d) j++;
			if(j>n) continue;
			if(b[j-1]>d) continue;
			int f=0;
			for(int k=i;k<j-1;k++) if(a[j]-a[k]<=d) f++;
			if(f==1) st[j]++;
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=st[i];
		cout<<ans<<"\n";
	}
	return 0;
}
