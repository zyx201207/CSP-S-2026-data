#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn],n,m;
bool vis[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i],vis[i]=1;
	for(int k=29;k>=1;k--){
		int cnt=0;
		for(int i=1;i<=n;i++) if(((a[i]>>k)&1)&&vis[i]) cnt++;
		if(cnt<m) continue;
		for(int i=1;i<=n;i++) if(!((a[i]>>k)&1)) vis[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if((a[i]&1)&&vis[i]) cnt++;
	if(cnt>=m) for(int i=1;i<=n;i++) if(!(a[i]&1)) vis[i]=0;
	int ans=(1<<29)-1+(1<<29);
	for(int i=1;i<=n;i++) if(vis[i]) ans&=a[i];
	cout << ans << endl;
	return 0;
}
