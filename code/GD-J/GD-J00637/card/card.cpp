#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ans[N],a[N];
int n,m,stk[N],top;
bool s[N];
void calc()
{
	top=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			s[j]=0;
		for(int j=i;j<=n;j++)
		{
//			for(int j=1;j<=top;j++)
//				cout<<stk[j]<<" ";
//			cout<<"\n";
			if(s[a[j]])
			{
				while(stk[top]!=a[j])
				{
					s[stk[top]]=0;
					top--;
				}
			}
			else stk[++top]=a[j];
			s[a[j]]=1;
		}
		for(int j=1;j<=top;j++)
			ans[stk[j]]++;
		top=0;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
			ans[a[i]]=i;
	}
	else
	{
		calc();
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
