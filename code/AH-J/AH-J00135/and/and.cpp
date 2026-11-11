#include<bits/stdc++.h>
using namespace std;
int n,m1,a[200005],b[200005],maxn=-1,maxn2=-1,ans,cnt,cnt1,cnt3;
string s,s1,s2;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
			maxn=a[i];
	}
	if(m1==1)
	{
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	maxn2=a[n-1];
	for(int j=30;j>=0;j--)
	{
		if(maxn>pow(2,j))
		{
			s+='1';
			cnt++;
			maxn-=pow(2,j);
		}
		else if(cnt!=0)
			s+='0';
	}
	for(int j=30;j>=0;j--)
	{
		if(maxn2>pow(2,j))
		{
			s1+='1';
			cnt1++;
			maxn2-=pow(2,j);
		}
		else if(cnt1!=0)
			s1+='0';
	}
	for(int i=0,j=s1.size();i<j;i++)
	{
		if(s[i]==s1[i])
			s2+='1';
		else
			s2+='0';			
	}	
	cnt3=s2.size();
	for(int i=0;i<cnt;i++)
	{
		s2[i]-='0';
		ans=ans+pow(2,cnt3-1)*s2[i];
		cnt--;
	}
	cout<<ans;
	return 0;
}
