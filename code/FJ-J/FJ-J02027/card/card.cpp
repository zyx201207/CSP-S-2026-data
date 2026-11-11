#include<bits/stdc++.h>
using namespace std;
ifstream fin("card.in");
ofstream fout("card.out");
int main(){
	int n,m,a[501],b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<m;k++){
		for(int i=0;i<n;i++){
			for(int j=i;j>0;j++){
				if(a[i]==a[j]){
					while(j>0){
						a[j]=0;
						j--;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			cout<<a[i];
		}
	}
	return 0;
} 
