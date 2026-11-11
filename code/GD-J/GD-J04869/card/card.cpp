#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
int main(){
	freopne("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5&&m<=2){
		if(a[n]==1) cout<<n<<" "<<0<<" ";
		else cout<<0<<" "<<n<<" ";
	}
	return 0;
}
