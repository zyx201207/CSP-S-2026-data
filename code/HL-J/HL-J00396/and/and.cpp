#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		maxn=max(a,maxn);
	}
	if(m==1) cout<<maxn;

	return 0;
}

