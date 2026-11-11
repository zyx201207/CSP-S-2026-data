#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005],len;
char c[200005],s[200000005];
void solve1()
{
	int temp=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=a[i];++j)
		{
			s[++temp]=c[i];
		}
	/*for(int i=1;i<=len;++i)
	{
		cout<<s[i]<<" ";
	}
	cout<<"\n";*/
	for(int i=1;i<=len/2;++i)
		if(s[i]!=s[len-i+1])
			++ans;
	cout<<ans;
}
void solve2()
{
	long long l=1,r=n,nowl=a[1],nowr=a[n],totl=0,totr=0;
	bool issame=1;
	for(int i=1;i<=n-1;++i)
		if(c[i]!=c[i+1])
		{
			issame=0;
			break;
		}
	if(issame)
	{
		cout<<0;
		return;
	}
	while(totl<=len/2&&totr<=len/2&&(totl+totr)<len&&l!=r)
	{
		if(c[l]!=c[r])
		{
			if(nowl<=nowr)
			{
				ans+=nowl;
				nowr-=nowl;
				if(nowr==0)
				{
					totr+=a[r];
					--r;
					nowr=a[r];
				}
				totl+=a[l];
				++l;
				nowl=a[l];
			}
			else
			{
				ans+=nowr;
				nowl-=nowr;
				totr+=a[r];
				--r;
				nowr=a[r];
			}
		}
		else
		{
			if(nowl<=nowr)
			{
				nowr-=nowl;
				totr+=a[l];
				++l;
				nowl=a[l];
			}
			else
			{
				nowl-=nowr;
				totr+=a[r];
				--r;
				nowr=a[r];
			}
		}
		//cout<<l<<" "<<nowl<<" "<<totl<<" "<<r<<" "<<nowr<<" "<<totr<<"\n";
	}
	cout<<ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	//cout<<len<<"\n";
	if(len<=2e9)
		solve1();
	else
		solve2();
	return 0;
}
