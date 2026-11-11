#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200002];
int num[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			num[a[j]]++;
			for(int k=n;k>=j+1;k--){
				if(a[k]==a[j]){
					j=k;
					break;
				}
			}
			
	    }
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
