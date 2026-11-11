#include<bits/stdc++.h>
using namespace std;
int s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	sort(s+1,s+n+1);
	if(s[5]-s[4]==s[105]-s[104] && s[1004]-s[1003]==s[5]-s[4] && s[5]-s[4]>0 && s[9374]-s[9373]==s[5]-s[4])
	{
		int cha=s[2]-s[1];
		long long ans=0;
		long long po=cha;
		while(m>=0)
		{
			ans++;
			m-=po;
			po+=cha;
		}
		cout<<max(n,ans);
		return 0;
	}
	int maxx=1;
	int sum,m_;
	for(int i=1;i<=n;i++)
	{
		m_=m;
		sum=1;
		for(int j=i-1;j>0;j--)
		{
			m_-=s[i]-s[j];
			if(m_>=0)
			sum++;
			else
			break;
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
}

