#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+3;
int n,m;
int tot[36],vis[N];
ll a[N],ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=30;j>=0;j--){
			if(a[i]&(1<<j))
				tot[j]++;
		}
	}
	for(int j=30;j>=0;j--){
		if(tot[j]<m) continue;
		int nwcnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1) continue;
			if((a[i]&(1<<j))==0) vis[i]=1;
			else nwcnt++;
		}
		if(nwcnt>=m) ans|=(1<<j);
	}
	printf("%lld",ans);
	return 0;
}
