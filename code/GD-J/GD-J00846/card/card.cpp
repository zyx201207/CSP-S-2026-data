#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)cin >> a[i];
		int ans[600010];
		for(int i=1;i<=n;i++){
			int l=i;
			map<int,int> mp;
			for(int j=l;j<=n;j++){
				if(mp[a[j]]==1)l=j;
				else mp[a[j]]++;
		}
		for(int j=l;j<=n;j++){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[a[i]] << " ";
	}
	return 0;
} 
