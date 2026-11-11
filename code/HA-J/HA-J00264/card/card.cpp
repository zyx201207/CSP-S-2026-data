#include<bits/stdc++.h>
using namespace std;
int n,a[500009],b,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b;
		a[b]=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cout<<i<<" ";
		}
	}
	return 0;
}
