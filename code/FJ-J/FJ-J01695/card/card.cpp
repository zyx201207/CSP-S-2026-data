#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]==a[i];
		for(int j=1;j<=m;j++){
			if(a[i+1]==b[j]){
				for(int k=j;k<=m;k++){
					b[k]==0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]==0){
			return 0;
		}
		cout<<b[i]<<" ";
	}
	return 0;
} 
