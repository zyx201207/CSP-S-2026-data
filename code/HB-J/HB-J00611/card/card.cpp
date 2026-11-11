#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1])b[a[i-1]]=i-1;
	}
	for(int i=1;i<=m;i++){
		if(b[i]==0) cout<<n<<' ';
		else cout<<b[i]<<' ';
	}
	return 0;
}
