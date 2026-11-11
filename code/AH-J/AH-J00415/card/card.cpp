#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005];
    cin>>n>>m;
    int b[m+5]={0};
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					j=max(j,k);
				}
			}
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout <<b[i]<<" ";
	}
    return 0;
}
