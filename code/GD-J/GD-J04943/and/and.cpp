#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,b[N],cnt;
void dfs(int x,int y){
	if(x>n||y>m) {
		if(cnt!=m) return ;
		int sum=b[1];
		for(int i=2;i<=cnt;i++){
			if(b[i]==-1) continue;
			sum=sum&b[i];
		}
		ans=max(ans,sum);
		return ;
	}
	b[++cnt]=a[x];
	dfs(x+1,y+1);
	b[cnt]=-1;
	cnt--;
	dfs(x+1,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(b,-1,sizeof b);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	cout<<ans;
	return 0;
} 
