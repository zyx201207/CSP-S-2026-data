#include<bits/stdc++.h>
using namespace std;
int aa[500005],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];			
	}
	for(int i=1;i<=m;i++){
		cout<<aa[i];			
	}
	
	return 0;
}
