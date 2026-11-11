#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],f[500010],lst[500010],t[500010],ans[500010],fl[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=lst[a[i]];
		for(int j=lst[a[i]]+1;j<i;j++){
			t[j]=max(t[j],lst[a[i]]);
		}
		lst[a[i]]=i;
	}
	memset(fl,127,sizeof fl);
	for(int i=n;i>=1;i--){
		if(fl[a[i]]<=t[i]) continue;
		ans[a[i]]=ans[a[i]]+(i-t[i]);
		fl[a[i]]=t[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
