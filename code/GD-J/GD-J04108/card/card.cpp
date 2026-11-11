#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=3e5+10;

int n,m;
int a[maxn],ans,maxx;
map<int,int>mp;

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for (int ___=1;___<=n;++___){
		map<int,bool>vis;vector<int>tmp;
		for (int i=___;i<=n;++i){
			if (vis[a[i]]==0){
				vis[a[i]]=1;tmp.push_back(a[i]);
			}
			else {
				while (vis[a[i]]==0){
					vis[tmp.back()]=0;
					tmp.pop_back();
				}
				tmp.push_back(a[i]);
			}
		}
		for (int i=0;i<tmp.size();++i){
			++mp[tmp[i]];
		}
	}
	for (int i=1;i<=m;++i){
		cout<<mp[i]<<' ';
	}
	return 0;
}
/*
4 3
2 1 2 1 3
*/
