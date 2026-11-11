//GZ-J00153,遵义市第十九中学,刘婧妍。
#include<bits/stdc++.h>	
using namespace std;
long long a[10000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i++){
		cout<<i<<" ";
	}
	return 0;
}
