#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long ans[300005];
long long sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s[500005]={0};
		int o=0;
		map<long long,pair<bool,int>>vis;
		for(int j=1;j<=m;j++){
			vis[j].first=0;
			vis[j].second=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]].first==0){
				s[++o]=a[j];
				vis[a[j]].first=1;
				vis[a[j]].second=o;
			}else{
				o=vis[a[j]].second;
			}
		}
		for(int j=1;j<=o;j++){
			cout<<s[j]<<" ";
			ans[s[j]]++;
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
