#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,tot=0;
int a[200005],s1[200005],s2[200005];//s1:1~n/2  s2:n/2+1~n
char ch[200005],c1[200005],c2[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> ch[i];
		tot+=a[i];
	}
	int sum=0,cur1=0,cur2=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>=tot/2)
		{
			sum-=a[i];
			s1[++cur1]=(tot/2)-sum;
			c1[cur1]=ch[i];
			break;
		}
		s1[++cur1]=a[i];
		c1[cur1]=ch[i];
	}
	sum=0;
	for(int i=n;i>=1;i--)
	{
		sum+=a[i];
		if(sum>=tot/2)
		{
			sum-=a[i];
			s2[++cur2]=tot/2-sum;
			c2[cur2]=ch[i];
			break;
		}
		s2[++cur2]=a[i];
		c2[cur2]=ch[i];
	}
//	for(int i=1;i<=cur1;i++)
//	{
//		cout << s1[i]<<" "<<c1[i] << endl;
//	}
//	for(int i=1;i<=cur2;i++)
//	{
//		cout << s2[i] <<" "<<c2[i]<< endl;
//	}
	int ans=0;
	int l=1,r=1;
	while(!(l>cur1&&r>cur2))
	{
		if(c1[l]!=c2[r])
		{
			//cout << min(s1[l],s2[r]) <<"in" << endl;
			ans+=min(s1[l],s2[r]);
		}
		int minn=min(s1[l],s2[r]);
		s1[l]-=minn;
		s2[r]-=minn;
		if(s1[l]<=0)l++;
		if(s2[r]<=0)r++;
	}
	cout << ans<<endl;
	return 0;
} 
