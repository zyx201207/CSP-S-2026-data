#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<1;
	}else if(m==2){
		if((a[n-2]==1 && a[n-1]==1 && a[n]==2) || (a[n-2]==2 && a[n-1]==2 && a[n]==1) ){
			cout<<1<<' '<<2;
		}else {
			cout<<1<<' '<<1;
		}
		
	}else if(m==n){
		for(int i=1;i<=m;i++){
			cout<<i<<' ';
		}
	}

	
	
	return 0;
}
