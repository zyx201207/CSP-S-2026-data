#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
ll a[2000005];
int n;
ll m;
int mx;
int ans;
int ove;
void dfs(int now,int used){
	if(now==ove){
		if(used==mx)ans++;
		return;
	}
	if(ans>2)return;
	if(used==mx)return;
	for(int i=now+1;i<=ove;i++){
		if(a[i]-a[now]>m)break;
		dfs(i,used+1);
		if(ans>2)return;
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	for(int ld=1;ld<=T;ld++){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		int pir=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			mx=1;
			int start=i;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[start]>m){
					mx++;
					start=j;
				}
				ans=0;
				ove=j;
				dfs(i,0);
				if(ans==2)pir++;
			}
		} 
		cout<<pir<<'\n';
	} 
	return 0;
}
