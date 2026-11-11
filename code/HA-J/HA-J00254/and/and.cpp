#include<bits/stdc++.h>

using namespace std;
long long n,m,maxx=-1e9,a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		maxx=max(a,maxx);
	}cout<<maxx;
	return 0;
}
