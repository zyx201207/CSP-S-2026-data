#include<bits/stdc++.h>
using namespace std;
int n,m,pd[500010],ans[300010],lp[300010],cp[300010];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pd[i];
		lp[pd[i]]=i;
		cp[pd[i]]++;
	}
	for(int i=1;i<=m;i++){
		for(int j=lp[i];j<=n;j++){
			ans[pd[j]]+=cp[i];
			j=lp[pd[j]];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	
	return 0;
}