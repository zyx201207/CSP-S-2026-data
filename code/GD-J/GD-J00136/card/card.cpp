#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],ans[300010];
int mp[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int l=i;//*upper_bound(mp[a[n]].begin(),mp[a[n]].end(),l-1)-1;
		while(l<=n){
			l=mp[a[l]];
			ans[a[l]]++;
			l++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
} 
//10
//9
//7
//8 10 10
