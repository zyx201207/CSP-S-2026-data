#include<bits/stdc++.h>
#include<map>
using namespace std;
map<int,int> mp;
int a[500005],ans[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0)mp[a[j]]++;
			else mp.clear();
		}
		for(int j=1;j<=m;j++)if(mp[a[j]]==1)ans[a[j]]++;
	}
	for(int j=1;j<=m;j++)cout<<ans[a[j]]<<" ";
	return 0;
}
