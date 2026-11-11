#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int q=500000;
typedef long long ll;

ll n,m,ans;
vector<int> a(q,0),b(q,0);

//int check(int pos)
//{
//	ll num=0;
//	if(m>0 && pos>=0)
//	{
//		 
//		for(int i=pos;i>=1;i--)
//		{
//			if(m-(pos-a[i])>0)
//			{
//				b[i]=b[pos];
//				m-=pos-a[i];
//			}
//			else break;
//		}
//		for(int i=1;i<=n;i++)
//		{
//			if(b[i]==b[pos])
//			{
//				num++;
//			}
//		}
//	}
//	return abs(num-ans);
//}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll mid=n/2+1;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[mid];
	}

	ll ans=0;
	for(int i=mid;i>=1;i--)
	{
		if(m>0 && m+b[i]>=0 && b[i]<0)
		{
			m+=b[i];
			b[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			ans++;
		}
	}
//	if(m>0)
//	{
//		ll ans1=0;
//		ll pos=-100;
//		for(int i=1;i<=n;i++)
//		{
//			if(a[i]!=0 && m>0)
//			{	
//				pos=i;
//				ans1=check(pos);
//				ans=max(ans,ans1);
//			}
//		}
//	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
