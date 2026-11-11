#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,maxl=1e3+10; 
int n,m;
int top=0;
int a[N],stk[N],ans[N];
bool flag[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++) ans[i]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int op=1;op<=n;op++)
	{
		top=0;
		for(int i=1;i<=n;i++) flag[i]=false;
		for(int i=op;i<=n;i++)
		{
			if(flag[a[i]])
			{
				while(top && stk[top]!=a[i]) flag[stk[top--]]=false;
				if(top) top--;
			}
			stk[++top]=a[i];
			flag[a[i]]=true;
		}
		for(int i=1;i<=top;i++) ans[stk[i]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i!=m) cout<<" ";
	}
	return 0;
}
