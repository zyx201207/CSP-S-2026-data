#include<bits/stdc++.h >
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	int a[n];
	int o[m+1]={0};
	int w[n];
	int r=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		r=0;
		for(int j=i-1;j<n;j++){
			w[r]=a[j];
			for(int l=0;l<r;l++){
				if(w[l]==w[r]){
					for(int q=l;q<r;q++){
						w[q]=0;
					}
				}	
			}
			r++;
		}
		for(int j=0;j<r;j++){
			o[w[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<o[i]<<' ';
	}
} 

