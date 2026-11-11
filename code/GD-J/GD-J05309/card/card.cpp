#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,shu[300005],sh[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])t=1;
	}
	if(t==0)
	{
		t=1;
		for(int i=2;i<=n+1;i++)
		{
			if(a[i]!=a[i-1])
			{
				cout<<t<<" ";
				t=0;
			}
			t++;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(shu[a[j]]==1)
			{
				t=j;
				t--;
				shu[a[j]]--;
				while(a[j]!=a[t])
				{
					if(t<i)break;
					shu[a[t]]=0;
					t--;
				}
			}
			shu[a[j]]++;
	    }
		for(int j=1;j<=m;j++)
		{
			sh[j]=sh[j]+shu[j];
			shu[j]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<sh[i]<<" ";
	
	return 0;
}
