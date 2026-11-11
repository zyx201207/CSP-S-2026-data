#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[56]={0},i=0,j=0;
	cin>>n>>m;
	int b[56]={0};
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<=i;j++){
				if(a[i]==a[j]){
					for(int n=0;n<56;n++){
						a[n]=a[i];
						a[i]=0;
					}
				}
			}
		}
		sort(a,a+56);
		for(i=0;i<56;i++){
			b[a[i]]+=1;
		}
	}
	for(int k=0;k<56;k++){
		if(b[k]!=0){
			cout<<b[k]<<' ';
		}
	}
	return 0;
} 
