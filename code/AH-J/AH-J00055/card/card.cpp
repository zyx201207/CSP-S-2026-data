#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+10;
int n,m,a[N],vis[N],b[N],num,ans[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=n;++i){
		num=0;
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;++j){
			if(vis[a[j]]){
				int num1=vis[a[j]]-1;
				for(int k=vis[a[j]];k<=num;++k){
					vis[b[k]]=0;
					b[k]=0;
				}
				num=num1;
				b[++num]=a[j];
				vis[a[j]]=num;
			}else{
				b[++num]=a[j];
				vis[a[j]]=num;
			}
		}
		for(int j=1;j<=num;++j){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout << ans[i] << ' ';
	}
	return 0;
}
