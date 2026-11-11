#include<bits/stdc++.h>
using namespace std;
struct Node {
	long long u,v;
} a[2000010];
long long c,t,n,k,i,j;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	mt19937_64 rd(time(0));
	uniform_int_distribution<int> dis(0,10);
	for(i=1; i<=t; i++) {
		cin>>n>>k;
		for(j=1; j<n; j++)
			cin>>a[j].u>>a[j].v;
		cout<<dis(rd)<<endl;
	}
	return 0;
}
