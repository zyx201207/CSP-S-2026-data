#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<a[n-m];
	return 0;
}
