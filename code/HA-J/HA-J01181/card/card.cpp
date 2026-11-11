#include <bits/stdc++.h>
using namespace std;
int n,m,top=0;
int a[500005];
int b[500005];
void push(int x)
{
	b[++top]=x;
}
void search(int x)
{
	int flag=0;
	for(int k=1;k<=top;k++)
	{
		if(b[k]==x)flag=k;
		if(flag)b[k]=0;
	}
	if(flag)top=flag;
}
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	int t[m+5]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			search(a[j]);
			push(a[j]);
		}
		for(int j=1;j<=top;j++)t[b[j]]++;
		top=0;
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" "; 
	return 0;
} 
