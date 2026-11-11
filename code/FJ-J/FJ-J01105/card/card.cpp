#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	char a[500005];
	for(int i=1;i<=n;++i)
    {
    	cin>>a[i];
	}
	int cnt[300005];
	for(int i=1;i<=n;++i)
	{
		int f=0;
		string s;
		for(int j=i;j<=n;++j)
		{
			int t=s.find(0,n,'0');
			if(t!=-1)
		    {
		    	if(s.find(0,n,a[i])!=-1)
		    	{
		    		s[s.find(0,n,a[i])]='0';
				}
				f=t;
			}
			else
		    {
		    	if(s.find(0,n,a[i])!=-1)
		    	{
		    		s[s.find(0,n,a[i])]='0';
				}
			}
			s+=a[i];
		}
		for(int j=f+1;j<=n;++j)
		{
			++cnt[int(a[i])];
		} 
	}
	for(int i=1;i<=m;++i)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
}
