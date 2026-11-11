#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
ll n,m,a[maxn];
bool vis[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=a[n];
	vis[n]=1;
	for(int i=2;i<=m;i++){
		int mx=0,mxidx=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if(mx<(a[j]&ans)){mxidx=j;mx=a[j]&ans;}
			}
		}
		vis[mxidx]=1;
		ans=ans&a[mxidx];
	}cout<<ans;
	return 0;
}
