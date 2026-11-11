#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],c[1000000],op=0;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		op=0;
		c[op]=a[i];
		for(int j=i+1;j<n;j++){
			int pd=0;
			for(int k=0;k<=op;k++){
				if(c[k]==a[j]){
					pd=1;
					op=k;
					break;
				}
			}
			if(pd=0){
				op++;
				c[op]=a[j];
			}
		}
		for(int j=0;j<=op;j++){
			b[c[j]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
