#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,p[200010],sum,kk,ans;
struct node
{
	int x;
	char ch;
}a[200010],b[400010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].ch;
		sum+=a[i].x;
		if(!kk&&sum>(n/2)) kk=i;
		p[i]=sum;
	}
	int tot=0,now=0,l=n;
	for(int i=1;i<=n;i++)
	{
		//cout<<i<<' '<<a[i].x<<endl;
		while(sum-p[l-1]<=a[i].x+tot&&l>1)
		{
			l--;
			//cout<<' '<<p[l]<<' '<<l<<' '<<now<<endl;
			b[++cnt]={sum-p[l]-now,a[i].ch};
			now=sum-p[l];
		}
		if(now<a[i].x+tot) b[++cnt]={a[i].x+tot-now,a[i].ch};
		now=a[i].x+tot;
		tot+=a[i].x;
		//cout<<cnt<<now<<tot<<endl;
	}
	//for(int i=1;i<=cnt;i++)
		//cout<<b[i].x<<endl;
	for(int i=1;i<=cnt/2;i++)
	{
		if(b[i].ch!=b[cnt-i+1].ch) ans+=b[i].x;
	}
	cout<<ans<<endl;
	
	return 0;
}
/*
3
2 a
2 b
1 c

*/
