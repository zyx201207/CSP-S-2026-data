#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MaxN=5e5;
const int MaxM=3e5;
int n,m;
int a[MaxN+32],ans[MaxM+32],wz[MaxM+32],num[MaxN+32],cnt;
bool A=true;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		wz[a[i]]=i;
		if(a[i-1]>a[i])A=false;
    }
    if(m==1)
    {
    	cout<<n;
    	return 0;
    }
    if(m==2)
    {
    	ans[a[n]]=n;
    	int flag=a[n]==2?1:2;
    	for(int i=1;i<=n;i++)
    		ans[flag]+=a[i]==flag;
    	cout<<ans[1]<<' '<<ans[2];
    	return 0;
    }
    if(A)
    {
    	for(int i=1;i<=m;i++)
    		cout<<wz[i]<<' ';
    	return 0;
    }
    for(int i=1;i<=n;i++)
    {
    	cnt=0;
    	for(int j=i;j<=n;j++)
    	{
    		int pos=cnt+1;
    		for(int k=1;k<=cnt;k++)
    			if(num[k]==a[j]){pos=k;break;}
    		num[pos]=a[j];cnt=pos;
    	}
    	for(int j=1;j<=cnt;j++)
    		ans[num[j]]++;
    }
    for(int i=1;i<=m;i++)
    	cout<<ans[i]<<' ';
	return 0;
}
