#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int nex[500005];
int la[300005];
int f[500005];
int res[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(la[a[i]]){
			nex[la[a[i]]]=i;
		}
		la[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]+=1;
		if(!nex[i-1])f[i]+=f[i-1];
		f[nex[i]]+=f[i];
	}
	for(int i=1;i<=n;i++){
		if(!nex[i])res[a[i]]+=f[i];
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
	}
	return 0;
}
