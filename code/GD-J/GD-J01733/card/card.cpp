#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],p[500005],nxt[500005],ans[500005];
struct tni{
	int x,val;
};
vector<tni> f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		nxt[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;
		for(int j=0;j<(int)f[i].size();j++){
			ans[f[i][j].x]+=f[i][j].val;
		}
		if(nxt[i]==0){
			f[i+1].push_back({a[i+1],ans[a[i]]});
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
