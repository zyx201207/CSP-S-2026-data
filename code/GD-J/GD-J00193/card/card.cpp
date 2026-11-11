#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,v[300005],tt;
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	t=n,tt=1;
	while(t--&&tt<=m)
	{
		s=' ';
		for(long long i=n-t+1;i<=n;i++)
		{
			long long f=0;
			for(long long j=n-t+1;j<i;j++)
			{
				if(a[i]==a[j])
				{
					f=1;
					s=' ';
					for(long long k=i;k<j;k++) s+=(char)a[k]+'0';
					break;
				}
			}
			if(f==0) s+=(char)a[i]+'0';
		}
		for(long long i=1;i<s.size();i++)
		{
			if((char)s[i]-'0'==tt) v[tt]++;
		}
		tt++;
	}
	for(long long i=1;i<=m;i++) cout<<v[tt]<<" ";
	return 0;
}
