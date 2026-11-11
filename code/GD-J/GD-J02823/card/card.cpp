#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],c[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]==2){
				b[a[j]]--;
			}
		}
		for(int k=1;k<=m;k++){
			if(b[k]==1){
				c[k]++;
			}
			b[k]=0;
		}
	}
	for(int i=1;i<=m-1;i++){
		cout<<c[i]<<" ";
	}
	cout<<c[m];
	return 0;
}
