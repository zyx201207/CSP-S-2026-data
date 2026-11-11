#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,del=0,m1;
int a[999999],g[999999],b[999999]; //平均达到后可以得到g[i]个水晶
int pre[999999],ans,num,cnt; 
bool flag=0;  
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[i]=1;
	}	
	sort(a+1,a+n+1);
	bool flg=1;
	int hsj,idx=0;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
		if(a[i]==hsj&&!flg)
		{
			g[idx]++;
		}
		else
		{
			flg=0;
			hsj=a[i];
			idx=i;
		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<pre[i]<<' ';
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	num=a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]+m<a[i+1]&&i!=n)
		{
			num=a[i+1];
			del=i;
			ans=max(ans,cnt);
			cnt=0;
			m=m1;
			continue;
		}
		if(g[i]==0)
		{
			cnt++;
			continue;
		}
		int need=(i-1-del)*(a[i]-num);
		//cout<<need<<endl;
		if(need<=m)
		{
			num=a[i];
			m-=need;
			cnt++;
			continue;
		}
		else
		{
//			cout<<cnt<<endl;
			cnt--;
			int chaiqian=num*min(g[i],cnt)-(pre[del+min(g[i],cnt)]-pre[del]);  
			need=need/(i-1-del)*(i-1-min(g[i],cnt)-del);
			if(chaiqian+m<need)
			{
				flag=1;
				break;
			}
			else
			{
//				cout<<chaiqian<<' '<<need<<endl;
				cnt++;
				m+=(chaiqian-need);
				//cout<<m<<endl;
				del+=g[i];
				num=a[i];
			}
		}
	}
	//cout<<num<<' ';
//	cout<<m<<' ';
	if(flag==1)
		cnt++;
	ans=max(ans,cnt);
	int leo=n-ans;
	for(int i=leo;i>=1;i--)
	{
		int need=(num-a[i]);
		if(need<=m)
		{
			ans++;
			m-=need;
		}
		else
			break;
	}
	cout<<ans;
	return 0;
}
/*
6 2
1 2 5 5 7 7
*/
 
