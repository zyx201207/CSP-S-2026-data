#include<bits/stdc++.h>
using namespace std;
int pianfen[10000001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>pianfen[i];
	cout<<pianfen[n];
	return 0;
}
