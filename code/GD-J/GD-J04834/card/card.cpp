#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

const int N=5e5,M=3e5;

int n,m;
int a[N+1];

int f[N+1];
int num[N+1],top;
int ans[M+1];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=n;i>=1;i--) cin>>a[i];
	
	int len=n;
	for(int p=1;p<=n;p++)
	{
		for(int i=1;i<=m;i++) f[i]=0;
		
		top=0;
		for(int i=len;i>=1;i--)
		{
			if(f[a[i]])
			{
				int l=f[a[i]];
				for(int k=top;k>=l;k--) f[num[k]]=0;
				top=l-1;
			}
			
			num[++top]=a[i],f[a[i]]=top;
		}
		for(int i=1;i<=top;i++) ans[num[i]]++;
		
		a[len--]=0;
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	
	
	return 0;
}

