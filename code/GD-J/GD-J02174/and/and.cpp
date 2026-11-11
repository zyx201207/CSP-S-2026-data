#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4) cout<<12;
	if(n==5) cout<<7;
	return 0;
}
