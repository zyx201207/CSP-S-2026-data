#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],ans;
char ch[N];
void check()
{
	int r=n;
	for(int i=1;i<=r;i++)
	{
		if(a[i]>a[r])
		{
			int sum=0,f=1,j=r;
			for(;j>i+1;j--)
			{
				sum+=a[j];
				if(ch[j]!=ch[i]) ans+=a[j];
				if(sum+a[j-1]>a[i])
				{
					f=0;
					break;
				}
			}
			if(!f)
			{
				a[i]-=sum;
				if(ch[j-1]!=ch[i]) ans+=a[i];
				a[j-1]-=a[i];
				
			}
			else i++;
			r=j-1;
		}
		else if(a[i]==a[r])
		{
			if(ch[i]!=ch[r]) ans+=a[i];
			a[i]=a[r]=0;
			i++,r--;
		}
		else if(a[i]<a[r])
		{
			int sum=0,f=1,j=i;
			for(;j<r-1;j++)
			{
				sum+=a[j];
				if(ch[r]!=ch[j]) ans+=a[j];
				if(a[j+1]+sum>a[r])
				{
					f=0;
					break;
				}
			}
			if(!f)
			{
				a[r]-=sum;
				if(ch[j+1]!=ch[r]) ans+=a[r];
				a[j+1]-=a[r];
				i=j+1;
			}
			else i+=j;
			r++;
		}
	}	
}
int t;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		t+=a[i];
		if(t>1e8) t=INT_MAX;
	}
	if(t==INT_MAX) check();
	else
	{
		string s;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s=s+ch[i];
			}
		}
		int l=0;
		t--;
		while(l<=t)
		{
			if(s[l]!=s[t]) ans++;
			l++,t--;
		}
	}
	cout<<ans;
	return 0;
}
