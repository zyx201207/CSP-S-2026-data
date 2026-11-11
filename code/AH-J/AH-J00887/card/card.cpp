#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int a[500005],cnt[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		map<int,int> mp;
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			if(mp.count(a[j])){
				for(int x=j-1;x>=i;x--){
					if(a[x]==a[j]){
						cnt[a[x]]--;
						break;
					}
					cnt[a[x]]--;
					mp[x]=0;
				}
			}else mp[j]=a[j];
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
