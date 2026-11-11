#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],ans[N],pos[N],vis[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ll l=i;
		for(int j=i;j<=n;j++){
			if(pos[a[j]]){
				for(int k=pos[a[j]];k<j;k++)pos[a[k]]=vis[a[k]]=0;
				l=j;
			}
			pos[a[j]]=j,vis[a[j]]=1;
		}
		for(int k=l;k<=n;k++)vis[a[k]]=1;
		for(int i=1;i<=m;i++)ans[i]+=vis[i],vis[i]=0,pos[i]=0;
	} 
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
