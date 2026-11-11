#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int h[m]={0},s=0;
	for(int j=0;j<n;j++){
		for(int z=n-1;z>j;z--){
			for(int i=z;i>j;i--){
				if(c[z]==c[i-1]){
					h[c[z]]++;
					continue;
					s=1;	
				}
			}
			if(s==1){
				continue;
			}
			else{
				h[c[z]]++;
			}
			
		}
	}
	h[c[n-1]]++;
	for(int s=1;s<=m;s++){
		cout<<h[s]<<" ";
	} 
	return 0;
} 
