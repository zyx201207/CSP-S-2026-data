#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1),l(m+1),g(n+2),s(n+2,1),r(m+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		g[i]=l[a[i]]+1;
	}
	for(int i=1;i<=n;i++){
		s[g[i]]+=s[i];
	}
	for(int i=1;i<=n;i++){
		r[a[i]]+=s[i];
	}
	for(int i=1;i<=m;i++){
		cout<<r[i]<<" ";
	}
	return 0;
}
