#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,c,t;
int a[2000005];
int up[2000005];
int down[2000005];
void solveA()
{
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]-a[1]>d)break;
		else cur++;
	}
	if(cur==1||cur==2||cur-1>(n+1)/2)cout <<0<<endl;
	else cout << n-2*(cur-1)+1<<endl;
}
int chk(int x)
{
	if(down[x]>=x-1||x==n)return 0;
	if(up[x-1]==up[x+1]&&down[x-1]==down[x+1])return 0;
	return (up[x-1]-up[x-2]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> a[i];
		if(c==11||c==12)
		{
			solveA();
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			up[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			down[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			//cout << up[i] << " "<<down[i] <<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i>=3)ans+=chk(i);
			//if(i>=3)cout <<chk(i) <<":"<< endl;
		}
		cout << ans << endl;
	}
	return 0;
}
