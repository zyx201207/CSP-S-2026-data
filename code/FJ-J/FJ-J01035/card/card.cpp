#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,M=3e5+10;
ll n,m;
ll a[N],last[M],ans[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(!last[a[j]]||last[a[j]]<i){
				last[a[j]]=j;
				continue;
			}
			if(!vis[last[a[j]]]){
				for(int k=last[a[j]];k<j;k++)vis[k]=1;
			}
			last[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(!vis[j])ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' '; 
	return 0;
}
