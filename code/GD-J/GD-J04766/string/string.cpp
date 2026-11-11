#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
int n,a[N],sum,ans,maxx,sss,h[N];
char c[N];
map<char,int>  dddd;
string s;
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s=s+c[i];
		}
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])
		{
			ans++;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		h[i]=h[i-1]+a[i];
		dddd[c[i]]++;
		maxx=max(maxx,a[i]);
	}
	for(char i='a';i<='z';i++)
	{
		if(dddd[i]!=0)
		{
			sss++;
		}
	}
	if(sss==1)
	{
		cout<<0;
		exit(0);
	}
	if(maxx<=50)
	{
		solve1();
	}
	else
	{
		for(int i=1,j=n;i<=j;i++,j--)
		{
			if(a[i]==a[j])
			{
				if(c[i]!=c[j])
				{
					ans+=a[j];
				}
			}
			else
			{
				if(a[i]>a[j])
				{
					int ned=a[i];
					int l=i+1,r=j-1;
					ans+=ned;
					while(l+1<r)
					{
						int mid=(l+r)/2;
						if(h[j]-h[mid-1]<=a[i]) l=mid;
						else r=mid; 
					}
					a[l]=a[l]-(ned-(h[j]-h[l]));
					a[j]=a[l];
					if(a[l]==0) l++;
					j=l;
				}
				
				else
				{
					int ned=a[i];
					int l=i+1,r=j-1;
					while(l+1<r)
					{
						int mid=(l+r)/2;
						if(h[mid]-h[i]<=a[j]) l=mid;
						else r=mid; 
					}
					ans+=ned;
					a[l]=a[l]-(ned-(h[l]-h[r]));
					a[i]=a[l];
					if(a[l]==0) l++;
					i=l;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
	
} 
