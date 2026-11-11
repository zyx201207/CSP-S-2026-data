#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],c[N],ans[N],top;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		top=0;
		for(int j=i;j<=n;j++)
		{
			c[a[j]]++;
			b[++top]=a[j];
			while(c[a[j]]>=1)
			{
			   	    c[b[top]]--;
			   	    top--;
		    }
		    c[a[j]]++;
            b[++top]=a[j];
		}
		for(int j=1;j<=top;j++)
		{
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

