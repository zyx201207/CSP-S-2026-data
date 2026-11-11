#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,m2,a[N],ans,cnt;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	m2=m;
	for(int i=1;i<=n;i++) cin>>a[i];
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
	cout<<ans;
	//for(int i=1;i<=n;i++) cout<<st[i].a;
	return 0;
}
