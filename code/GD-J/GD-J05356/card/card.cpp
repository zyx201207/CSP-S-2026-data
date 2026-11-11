#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],k=1,b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=k;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[a[j]]++;
			}
			k++;
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
		}
	}
	if(m==1){
		cout<<n;
	} 
	return 0;
}
