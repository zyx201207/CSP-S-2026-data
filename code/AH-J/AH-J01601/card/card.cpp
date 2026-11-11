#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++)	cin>>a[i];
	for (int i=1;i<n;i++){
		if(a[i]!=a[i-1])	cout<<i<<" ";
	}
	cout<<n;
	return 0;
}
