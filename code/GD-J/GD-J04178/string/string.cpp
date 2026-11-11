#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int N=2e5+5;
struct node
{
	ll num;
	char c;
}a[N];
ll s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i].num);
		cin>>a[i].c;
		s=s+a[i].num;
	}
	ll ave;
	ave=s/2;
	int l=1,r=n;
	ll cnt1=0ll,cnt2=0ll,ans=0ll;
	while(cnt1!=ave&&cnt2!=ave&&l<=r)
	{
//		cout << l << " " << r << endl ;
		if(l==r) break;
		if(a[l].c==a[r].c)
		{
			if(a[l].num>a[r].num)
			{
				a[l].num=a[l].num-a[r].num;
				cnt1=cnt1+a[r].num;
				cnt2=cnt2+a[r].num;
				a[r].num=0;
				r--;
			}
			else if(a[l].num<a[r].num)
			{
				a[r].num=a[r].num-a[l].num;
				cnt1=cnt1+a[l].num;
				cnt2=cnt2+a[l].num;
				a[l].num=0;
				l++;
			}
			else if(a[l].num==a[r].num)
			{
				cnt1=cnt1+a[l].num;
				cnt2=cnt2+a[r].num; 
				a[r].num=0;
				a[l].num=0;
				l++;
				r--;
			}
		}
		else
		{
			if(a[l].num>a[r].num)
			{
				a[l].num=a[l].num-a[r].num;
				cnt1=cnt1+a[r].num;
				cnt2=cnt2+a[r].num;
				ans=ans+a[r].num;
				a[r].num=0;
				r--;
			}
			else if(a[l].num<a[r].num)
			{
				a[r].num=a[r].num-a[l].num;
				cnt1=cnt1+a[l].num;
				cnt2=cnt2+a[l].num;
				ans=ans+a[l].num;
				a[l].num=0;
				l++;
			}
			else if(a[l].num==a[r].num)
			{
				cnt1=cnt1+a[l].num;
				cnt2=cnt2+a[r].num; 
				ans=ans+a[l].num; 
				a[r].num=0;
				a[l].num=0;
				l++;
				r--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
