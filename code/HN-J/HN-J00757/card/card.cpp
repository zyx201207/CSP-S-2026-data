#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000005],b[5000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]!=a[j-1]){
				b[a[i]]++;
			}		
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
