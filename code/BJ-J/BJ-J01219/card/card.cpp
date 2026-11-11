#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[500010]; 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	if(n==1){
		for(int i=1;i<=m;i++){ if(a[i]==i) cout<<1<<" "; else cout<<0<<" ";}
		
		}
	return 0;
}
