#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[300005];
bool f[300005],F=1;
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n&&F;i++)if(a[i]>a[i+1])F=0;
	if(F){
		for(int i=1;i<=n;i++)ans[a[i]]++;
		for(int i=1;i<=m;i++)ans[i]+=ans[i-1],cout<<ans[i]<<" ";
		return 0;
	}
	vector<int>nw;
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof 0);
		for(int j=i;j<=n;j++){
			if(f[a[j]])while(!nw.empty()&&nw[nw.size()-1]!=a[j])f[nw[nw.size()-1]]=0,nw.pop_back();
			else nw.push_back(a[j]),f[a[j]]=1;
		}
		for(int i:nw)ans[i]++;
		while(!nw.empty())nw.pop_back();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
