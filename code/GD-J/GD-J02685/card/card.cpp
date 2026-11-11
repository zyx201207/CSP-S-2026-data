#include<bits/stdc++.h>
using namespace std;
int n,m,sum,maxx,a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		b[a[i]]++;
	}
	b[a[n]]=n;
	for(int i=1;i<=maxx;i++) cout<<b[i]<<" ";
	return 0;
}
