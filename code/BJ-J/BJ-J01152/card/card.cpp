#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll n,m,a[maxn],tot,sum[maxn],lst[maxn],vis[maxn],ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[n]==1)ans[1]++;
			else if(a[i]==2&&a[n]==2)ans[2]++;
			else {
				ans[1]++;
				ans[2]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
		return 0;
	}
	
	for(int i=1;i<=m;i++){
		ans[i]=lst[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
