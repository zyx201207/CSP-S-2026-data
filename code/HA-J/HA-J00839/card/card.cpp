#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
long long a[MAXN],ans=-1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int c=m-2;
	for (int i=1;i<=n;i++) cin>>a[i];
	cout<<m<<' ';
	for (int i=1;i<=c;i++) cout<<n-m<<' ';
	cout<<n;
	return 0;
}




