#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			cout<<i-1<<" ";
		}
	}
	cout<<n;
	return 0;
}

