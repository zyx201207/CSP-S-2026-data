#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=rand()%5000+1;i++){
		cout<<a[rand()%m+1]<<' ';
	}
	return 0;
}
