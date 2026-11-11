#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]==1)cout<<n<<' '<<1;
	if(a[n]==2)cout<<1<<' '<<n;
	return 0;
}
