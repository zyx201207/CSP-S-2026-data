#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+200;
int n,m,a[N],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]=max(x,i);
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
