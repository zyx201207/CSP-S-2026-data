#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,a[N],m,ans[N];
struct node{
	int v;
}nu[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(nu,0,sizeof nu);
		for(int j=i;j<=n;j++){
			int l=a[j];
			if(nu[l].v==0) nu[l].v=++cnt;
			else{
				for(int t=1;t<=m;t++){
					if(nu[t].v>nu[l].v) nu[t].v=0;
				}
				cnt=nu[l].v;
			}
		}
		for(int j=1;j<=m;j++){
			if(nu[j].v!=0) ans[j]++;
		}
	}
	/*for(int i=1;i<=n;i++){
		int l=a[i];
		for(int j=i+1;j<=n;j++){
			if(l<a[j]) ans[l]++;
			l=a[j];
		}
		ans[a[n]]++;
	}*/
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
