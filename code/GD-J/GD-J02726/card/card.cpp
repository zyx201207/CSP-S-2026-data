#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],l[N],res;
vector<int> ans[N];
pair<bool,int> vis[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]].first){
				for(int k=vis[a[j]].second;k<j;k++)ans[i].erase();
				ans[i].push_back(a[j]);l[i]++;vis[a[j]].first=true;vis[a[j]].second=j;
			}
			else ans[i].push_back(a[j]);l[i]++;vis[a[j]].first=true;vis[a[j]].second=j;
		}
	}
	for(int i=1;i<=n;i++){
		res=0;
		for(int k=1;k<=n;k++){
			for(int j=1;j<=l[k];j++){
				if(ans[j]==i){
					res++;break;
				}
			}
		}
		cout<<res<<" ";
	}
	return 0;
}
