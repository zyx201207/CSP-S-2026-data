#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<n-a[i];
	}
	return 0;
	
}
