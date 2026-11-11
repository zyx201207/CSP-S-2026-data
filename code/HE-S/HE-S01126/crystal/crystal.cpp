#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
		int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>i;
		i+=i;
		cout<<i;
	}
	return 0;
}
