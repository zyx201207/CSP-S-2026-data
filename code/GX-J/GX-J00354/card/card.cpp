#include<bits/stdc++.h>
#define f(i,e,s) for(int i=e;i<=s;i++)
using namespace std;
typedef long long ll;
const ll N=5e5+10,G=5e2+8,inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll a[N];
ll vis[10086],st[10086];
ll sum[10086];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	f(i,1,n) cin>>a[i];
	f(i,1,n)
	{
		ll top=0;
//		memset(vis,0,sizeof(vis));
		f(j,1,m) vis[j]=0;
		f(j,i,n)
		{
			if(vis[a[j]])
			{
				f(k,vis[a[j]]+1,top) vis[st[k]]=0;
				top=vis[a[j]]-1;
			}
			st[++top]=a[j];
			vis[a[j]]=top;
		}
//		f(j,1,top) cout<<st[j]<<" ";
//		cout<<endl;
		f(j,1,top) sum[st[j]]++;
	}
	f(i,1,m) cout<<sum[i]<<" ";
	return 0;
}













































