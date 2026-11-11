#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+10;
ll a[MAXN],n,m,ans,cnt,vis[MAXN],b[MAXN],temp;
void dfs(int td){
	if(td==m){
		for(int i=0;i<n;i++){
			if(b[i]>0){
				temp=b[i];
				break;
			}
		}
		for(int i=0;i<n;i++){
			if(b[i]>0){
				temp=temp&b[i];
			}
		}
		ans=max(ans,temp);
		for(int i=0;i<n;i++){
			b[i]=0;
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[i]=a[i];
			td++;
			dfs(td);
			td=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
