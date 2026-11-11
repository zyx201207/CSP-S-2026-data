#include<bits/stdc++.h>
using namespace std;
int n,m,a[555555];
struct nnn
{
	int l=1e9,r=-1;
};
nnn b[333333];
vector<int>c[333333];
int ans=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]].l=min(b[a[i]].l,i);
		b[a[i]].r=max(b[a[i]].r,i);
		c[a[i]].push_back(i);
		if(i>1&&a[i]<a[i-1])f=1;
	}
	if(!f){
		for(int i=1;i<=m;i++)cout<<b[i].r<<' ';
    }
    else
    {int ans[11111]={0};
    	for(int i=1;i<=n;i++)
    	{bool b[11111]={0};
    		for(int j=i+1;j<=n;j++)
    		{
    			for(int k=i;k<j;k++)
    			{
    				if(a[k]==a[j])
    				{
    					for(int q=k;q<j;q++)b[q]=1;
					}
				}
			}
			for(int j=i;j<=n;j++)
			{
				if(b[j]==0)ans[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
}
