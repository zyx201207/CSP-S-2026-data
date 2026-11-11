#include<bits/stdc++.h>
using namespace std;
int n,m,a[214514],t[32],f[32],ans;
bool mycmp(int a,int b)
{	return a>b;
}
void work(int x)
{	int cnt=0;
	int r=x;
	while(r>0)
	{	r/=2;
		cnt++;		
	}
	if(f[cnt]<m) 
	{	if(f[cnt]==0) 
		{	t[cnt]=x;
			f[cnt]++;
		}
		else
		{	t[cnt]=t[cnt]&x;
			f[cnt]++;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];
	}
	sort(a+1,a+1+n,mycmp);
	for(int i=1;i<=32;i++)
	{	t[i]=1;	}
	for(int i=1;i<=n;i++)
	{	
		work(a[i]);
	}
	for(int i=1;i<=32;i++)
	{	
		if(f[i]==m)
		{	ans=max(ans,t[i]);	}
	}
	if(ans==0)
	{	ans=a[1];
		for(int i=2;i<=m;i++)
		{	ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
}
