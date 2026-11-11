#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[3001];
int n,m;
int main(){
	freopen("card.in", "r",stdin);
	freopen("card.out", "w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<int,int> mp;
		for(int j=i;j<=n;j++){
			if(mp.count(a[j]) && mp[a[j]] != 0){
				for(int k=mp[a[j]];k<j;k++){
					mp[a[k]] = 0;
				}
				
			}
			mp[a[j]] = j;
		}
		for(int j=1;j<=m;j++){
			if(mp.count(j) && mp[j] != 0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
