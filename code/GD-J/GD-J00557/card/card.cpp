#include<bits/stdc++.h>
using namespace std;
int last,n,m,pai[600000],zhuo[600000],dian[400000];
int main (){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>pai[i];
	}
	for(int i=0;i<n;i++){
		zhuo[0]=pai[i];
		last=0;
		for(int j=i+1;j<n;j++){
			for(int k=0;k<=last;k++){
				if(zhuo[k]=pai[j]){
					last=k-1;
					break;
				}
			}
			zhuo[last+1]=pai[j];
			last++;
		}
		for(int j=0;j<=last;j++){
			dian[zhuo[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dian[i]<<' ';
	}
	return 0;
}

