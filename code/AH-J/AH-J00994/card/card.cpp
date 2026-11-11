#include<bits/stdc++.h>
using namespace std;
long long a[500005],y[300005];
long long i,j,n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		y[a[i]]=i;
	}
	for(i=1;i<=m;i++){
		cout<<min(y[i],m)<<" ";
	}
	return 0;
}
