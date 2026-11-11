#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int k[N]={},s[N]={},ans[N]={};
bool vis[N]={};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>k[i];
	for(int i=n-1;i>=0;i--){
		if(!vis[k[i]]){
			vis[k[i]]=1;
			s[k[i]]=i;
		}else{
			for(int l=i+1;l<s[k[i]];l++)vis[k[l]]=0;
			s[k[i]]=i;
		}		
		for(int l=1;l<=m;l++){
			if(vis[l])ans[l]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
