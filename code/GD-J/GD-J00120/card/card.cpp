#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],b[300010],c[500010],cf[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],cf[a[i]]=i;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;){
			b[a[j]]++;
			if(cf[a[j]]!=j) j=cf[a[j]];
			j++;
		}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}/*
4 5 1 2 1 3
3
*/
