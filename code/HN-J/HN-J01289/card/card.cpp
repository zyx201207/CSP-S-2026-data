#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5],b[m+5]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[j]==a[k]){
					j=k;
					break;
				}
			}
			b[a[j]]++;
		}
	}
	for(int i=0;i<=m;i++){
		if(b[i]>0){
			cout<<b[i]<<' ';
		}
	}
	return 0;
}
