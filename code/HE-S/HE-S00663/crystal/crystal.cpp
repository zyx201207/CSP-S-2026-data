#include<bits/stdc++.h>
using namespace std;
#define int long long
//hope 60-80pts
const int N=5e5+10;
int n,m,cyn[N],pre[N],ans;
bool check(int st,int ed){
	return m>=cyn[ed]*(ed-st+1)-pre[ed]+pre[st-1];
}
signed main(){
	//cin.tie(0)->ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>cyn[i];
	sort(cyn+1,cyn+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+cyn[i];
	int st=1;
	for(int ed=1;ed<=n;ed++){
		while(!check(st,ed)) st++;
		ans=max(ans,ed-st+1);
	}
	cout<<ans;
	return 0;
} 
