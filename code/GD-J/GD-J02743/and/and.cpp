#include<bits/stdc++.h>
using namespace std;
int n,m,a,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k;
		k=max(a,k);
	}
	cout<<k;
	return 0;
}
