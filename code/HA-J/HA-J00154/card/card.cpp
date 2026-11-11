//CSP-J succeed

#include <bits/stdc++.h>
using namespace std;
#define llong long long

auto fr=[]()->void{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	return;
};

const int N=5e5+10;
int a[N];
unordered_map<int,int> la,ans;
unordered_map<int,pair<int,int>> us;
signed main()
{
	fr();
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; la[a[i]]=i;
	}
	
	int k=1;
	for(int i=1;i<=n;i++){
		if(!us[a[i]].first){
			us[a[i]].first=us[a[i]].second=i;
		}else
		{
			int u=us[a[i]].first, v=i, w=us[a[i]].second;
			us[a[i]].first=us[a[i]].second=i;
			for(int j=max(k,u+1);j<v;j++)
			{
				if(la[a[j]]==j){
					ans[a[j]]-=w;
				}else{
					us[a[j]].second-=w;
				}
			}
			
			k=max(k,v);
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]+la[i]<<' ';
	}
	
	return 0;
}
