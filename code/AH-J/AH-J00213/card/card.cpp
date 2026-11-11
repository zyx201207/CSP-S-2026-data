#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],p[300005],ans[300005];
bool _8=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],p[a[i]]=i,_8=_8&&(i==1||a[i-1]<=a[i]);
	if(_8){
		for(int i=1;i<=n;i++) ans[a[i]]++;
		for(int i=1;i<=m;i++) ans[i]+=ans[i-1];
	} else for(int i=1;i<=n;i++) for(int j=i;j<=n;j=p[a[j]]+1) ans[a[j]]++;
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
