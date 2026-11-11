#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,t,n,d,x[N],a[N],b[N];
bool check(int g,int h)
{
	for(int i=g+1;i<=h;i++) if(x[i]-x[i-1]>d) return 0;
	for(int i=1;i<=n;i++) a[i]=0;
	int m=0;
	for(int i=g;i<=h;i++) a[++m]=x[i];
	int s=1,D=d;
	for(int i=g+1;i<=h;i++) 
		if(x[i]-x[i-1]<=D) D-=x[i]-x[i-1];
		else s++,D=d;
	int sum=0;
	for(int mask=1;mask<(1<<m);mask++)
	{
		for(int i=1;i<=m;i++) b[i]=0;
		for(int i=1;i<=m;i++) if(mask&(1<<(i-1))) b[i]=1;
		if(b[1]==0||b[m]==0) continue;
		int k=0;
		for(int i=1;i<=m;i++) if(b[i]) k++;
		if(s==k-1) sum++;
		if(sum>2) return 0;
	}
	if(sum==2) return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c==0)
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			if(n<=9)
			{
				int ans=0;
				for(int i=1;i<=n;i++)
					for(int j=i+3;j<=n;j++)
						if(check(i,j)) ans++;
				cout<<ans<<"\n";
				continue;
			}
		}
	}
	return 0;
}
