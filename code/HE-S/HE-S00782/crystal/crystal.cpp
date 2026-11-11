#include<bits/stdc++.h>
using namespace std;
//定义区
long long flag=1,yicibiaoji=0,cnt=1,n,m,a[500010],f[500010],maxn; 
//定义区 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	f[1]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    for(int c=2;c<=n;)
    {
        f[c]=(c-flag)*(a[c]-a[c-1]);
        if(f[c]<=m)
        {
        	cnt++;
        	m-=f[c];
        	c++;
        	//cout<<m<<" ";
		}
		else
		{
			maxn=max(maxn,cnt);
			m+=a[c-1]-a[flag];
			flag++;
			cnt--;
		}
	}
    cout<<maxn<<endl;
	return 0;
}
