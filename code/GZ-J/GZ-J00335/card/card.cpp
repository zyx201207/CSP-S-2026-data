#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a],d[a],e[b];
	for(int i=0;i<a;i++){
		cin>>c[i];
		d[i]=c[i];
	}
	for(int i=0;i<a;i++){
		for(int j=i;j<a;j++){
	  	for(int l=i;l<j;l++){
				if(d[j]==d[l]){
					for(int o=l;o<j;o++){
						d[o]=0;
					}
				}
			}
		}
		for(int j=i;j<a;j++){
			if(d[j]!=0){
				e[d[j]-1]++;
			}
		}
	}
	for(int i=0;i<b;i++){
		cout<<e[b]<<" ";
	}
} 
