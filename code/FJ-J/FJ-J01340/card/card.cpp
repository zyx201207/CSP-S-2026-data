#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main( ){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(m<=2){
	for(int i=1;i<=n;i++){
		if(a[n]==1){
			if(a[i]==1){
			b[1]++;
			}
			else {
				b[1]++;
				b[2]++;
			}	
		}
		if(a[n]==2){
			if(a[i]==2){
			b[2]++;
			}
			else {
				b[1]++;
				b[2]++;
			}	
		}
	}
	}
	for(int i=1;i<=m;i++){
	cout<<b[i]<<' ';
	}
	
	return 0;
}
