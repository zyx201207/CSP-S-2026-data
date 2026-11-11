#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m,a[N],ans[N],t;
int main(){
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long bj[N]={0};
		for(int j=i;j<=n;j++)
		{
			if(bj[a[j]]!=0)
			{
				for(int k=1;k<=m;k++)
				{
					if(bj[k]>bj[a[j]]) 
					{
						bj[k]=0;
						t--;
					}
				}
				bj[a[j]]=t;
			}
			else
			{
				t++;
				bj[a[j]]=t;
			}
		}
		for(int k=1;k<=m;k++)
		{
			if(bj[k]!=0) 
			{
				ans[k]++;
			}
		}
		t=0;
	}
	for(int k=1;k<=m;k++)
	{
		cout<<ans[k]<<' ';
	}
	
	return 0;
}
/* j zu dou zha leTAT...*/

