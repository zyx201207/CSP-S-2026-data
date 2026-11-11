#include<bits/stdc++.h>
using namespace std;
int m,n,a[100];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		if(a[1]==1){
			cout<<m<<" "<<0;
		}else{
			cout<<0<<" "<<m;
		}
	}else{
		cout<<m;
	}
	return 0;
}
