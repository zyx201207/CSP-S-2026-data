#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],s,c,cnt[35],f,vis[N],now,p[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		c=a[i];
		for(int j=30;j>=0&&c;j--)
		{
			if(c&(1<<j))  
			{
				c-=(1<<j);
				cnt[j]++;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int j=30;j>=0;j--)  
	{
		if(cnt[j]>=m)
		{
			for(int i=n;i>=1;i--)
			{
				if(!(a[i]&(1<<j))||now==m)  continue;
				vis[i]=1;    
				now++;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++)  
	{
		if(vis[i])  
		{
			if(s==0)  s=a[i];
			else  s&=a[i];
		}
	}
	cout<<s;
	return 0;
}
