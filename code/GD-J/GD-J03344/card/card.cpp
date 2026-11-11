#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],n,m,l=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l=i;
		for(int k=n+1;k>=l;k--){
			if(a[k]==a[l]){
				l=k+1;
				b[a[k]]++;
				k=n+1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
