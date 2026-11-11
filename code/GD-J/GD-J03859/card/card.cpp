#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int v[N],a[N];
int mp[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1]) mp[a[i]]=max(mp[a[i]],i);
	for(int i=1;i<=m;i++) cout<<mp[i]<<" ";
	return 0;
}
