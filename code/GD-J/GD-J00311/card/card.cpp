#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005];
int a[500005];
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(mp[a[i]]==0){
			mp[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			ans[a[j]]++;
			j=mp[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
