#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+7;
int n,m,a[N],mx,tmp=1,ans[N][2005],tmp2;
bool vis[N];
void qpl(int x)
{
	for(int i=1;i<=n;i++)vis[i]=false;
	if(x==m+1){
		tmp++;tmp2=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans[tmp][++tmp2]=a[i];
			vis[i]=true;
			qpl(x+1);
			vis[i]=false;
		}
	}
} 
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	qpl(1);
	for(int i=1;i<=tmp;i++){
		int res=1;
		for(int j=1;j<=m;j++)res=res&ans[i][j];
		mx=max(mx,res);
	}
	cout<<mx;
	return 0;
}
