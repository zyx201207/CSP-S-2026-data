#include<bits/stdc++.h>
using namespace std; 
const long long N=2e5+5;
long long n,m,x,y,z,op,sum,t,k,a[N],b[N],f[N],flag,js[N],ans[N],last[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],last[a[i]]=i;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j=last[a[j]]+1)
			ans[a[j]]++;
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m)
			cout<<" ";
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	freopen("card2.in","r",stdin);
//	freopen("card2.out","w",stdout);
//	freopen("card3.in","r",stdin);
//	freopen("card3.out","w",stdout);
//	freopen("card4.in","r",stdin);
//	freopen("card4.out","w",stdout);
//	freopen("card5.in","r",stdin);
//	freopen("card5.out","w",stdout);
//	freopen("card6.in","r",stdin);
//	freopen("card6.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
