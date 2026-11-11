#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,a[N],ans=0,slen=0,s[N],e[N],l,r,k,lkc,rkc;
ll fs3,fs4;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		s[i]=slen+1;
		slen=slen+a[i];
		e[i]=slen;
	}
	if(slen%2==0)
	{
		ll fs1=slen>>1;
		ll fs2=fs1+1;
		for(ll i=1;i<=n;i++)
		{
			if(fs1>=s[i]&&fs1<=e[i]) fs3=i;
			if(fs2>=s[i]&&fs2<=e[i]) fs4=i;
		}
		if(fs3==fs4)
		{
			slen=0;
			for(ll i=1;i<=n;i++)
			{
				if(i==fs3)
				{
					a[i]--;
				}
				s[i]=slen+1;
				slen=slen+a[i];
				e[i]=slen;
			}
		}
		else if(fs3!=fs4)
		{
			if(c[fs3]!=c[fs4]) ans++;
			slen=0;
			for(ll i=1;i<=n;i++)
			{
				if(i==fs3)
				{
					a[i]--;
				}
				s[i]=slen+1;
				slen=slen+a[i];
				e[i]=slen;
			}
		}
	}
	if(slen%2!=0)
	{
		ll mid=slen>>1;
		mid=mid+1;
		for(ll i=1;i<=n;i++)
		{
			if(mid>=s[i]&&mid<=e[i])//字符串的中点是属于第i块的 
			{
				k=i;//块的归属为第i块 
				if(mid==e[i])//中间点是某一个块的最后一个 
				{
					r=i+1;
					rkc=a[r];
					l=i-(a[r-1]==1);//若中间点是单个一组，则左边的点所在块是左边的块  
					lkc=a[l];
					lkc--;
					if(a[r-1]!=1)
					{
						s[r-1]++;
					}
				}
				else if(mid==s[i])
				{
					l=i-1;
					lkc=a[l];
					r=i+(a[l+1]==1);
					rkc=a[r];
					rkc--;
					if(a[l+1]!=1)
					{
						s[l+1]++;
					}
				}
				else if(mid!=e[i]&&mid!=s[i])
				{
					l=i;
					r=i;
					lkc=e[i]-mid;
					rkc=mid-s[i];
				}
				break;
			}
		}
		while(l!=0&&r!=n+1)
		{
			if(c[l]!=c[r])
			{
				ans=ans+min(lkc,rkc);
			}
			if(lkc>rkc)
			{
				lkc=lkc-rkc;
				r++;
				rkc=a[r];
			}
			else if(rkc>lkc)
			{
				rkc=rkc-lkc;
				l--;
				lkc=a[l];
			}
			else if(lkc==rkc)
			{
				l--;
				r++;
				lkc=a[l];
				rkc=a[r];
			}
		}
		cout<<ans;
	}
	return 0;
}
