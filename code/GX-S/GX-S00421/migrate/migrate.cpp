#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,m2,a[N],b,ans,cnt;
bool f=true;
void check()
{
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		int j=1;
		//cout<<i<<endl;
		while(m2>=0&&i-j>=1)
		{
			m2-=(a[i]-a[i-j]);
			cnt++;
			//cout<<i-j<<" "<<cnt<<" "<<m2<<endl;
			j++;
		}
		if(m2>=0) ans=max(ans,cnt+1);
		else ans=max(ans,cnt);
		m2=m,cnt=0;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	m2=m;
	if(n>=2)
	{
		cin>>a[1]>>a[2];
		b=a[2]-a[1];
		for(int i=3;i<=n;i++) 
		{
			cin>>a[i];
			if(b!=a[i]-a[i-1]) f=false;
		}
		if(f==true)
		{
			m2=(m-m%b)/b;
			for(int i=1;i<=n-1;i++)
			{
				if(m2-=i>=0) m2-=i;
				else ans=i;
			}
		}
		else check();
	}
	else
	{
		for(int i=3;i<=n;i++) cin>>a[i];
		check();
	}
	cout<<ans;
	//for(int i=1;i<=n;i++) cout<<st[i].a;
	return 0;
}
