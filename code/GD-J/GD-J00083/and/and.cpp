#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m,cnt,a[N],b[N],id,ans;
bool vis;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=30;i>=0;i--)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i))
				cnt++,b[++id]=a[j];
		if(cnt<m)
			continue;
		ans+=(1<<i);
		n=id,id=0;
		for(int j=1;j<=n;j++)
			a[j]=b[j];
	}
	cout<<ans;
	return 0;
}
