#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
map<long long,long long> b[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[a[i]]+=1;
	}
	for(int i=1; i<=m; i++) {
		cout<<b[i]<<" ";
	}
	return 0;
}
