#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[500005],b[500005],c[500005],x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=0;k<x;k++){
				if(b[k]==a[j]){
					
				}
			}
		}
	}
	return 0;
}
