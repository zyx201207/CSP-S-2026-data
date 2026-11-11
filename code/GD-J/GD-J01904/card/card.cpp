#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2000010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	while(m--){
		cout<<n<<" ";
	}
	return 0;
}

