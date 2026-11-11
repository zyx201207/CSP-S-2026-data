#include<bits/stdc++.h>
using namespace std;

int a[5000010],ans[50000010],x[20010];
int main()
{
    freopen("card.in","r",stdin);
freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    	
    int mx=0;
    for(int i=1;i<=n;i++)
    	mx=max(mx,a[i]);
    	
	for(int i=1;i<=n;i++)
	{
		x[1]=a[i];
		int now=i;
		int xn=1;
		while(now<=n)
		{
			now++;
			for(int j=1;j<=xn;j++)
			{
				if(x[i]==a[now])
				{
					for(int k=j;k<=xn;k++)
						x[k]=0;
					xn-=xn-i;
					xn+=1;
					x[i]=a[now];
				}
			}
		}
		for(int i=1;i<=xn;i++)
			ans[x[i]]++;
			
	}
	
	for(int i=1;i<=mx;i++)
	{
		if(ans[i]!=0)
			cout<<ans[i]<<" ";
	}
    
    return 0;
}