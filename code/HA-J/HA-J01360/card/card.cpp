#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[3003],c[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int p=0;
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[k]==a[i]){
					p++;
					break;
				}
			}
		}
		cout<<p<<" ";
	}
	
	
	return 0;
}
