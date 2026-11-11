#include<bits/stdc++.h>
using namespace std;
	long long m,n,a[1000000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]+2;
	}
	return 0;
}

