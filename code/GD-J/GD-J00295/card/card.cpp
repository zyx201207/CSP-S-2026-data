#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int b[2*n]={0},c[m]={0},x=0,d[m]={0};
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			b[x]=a[j];
			x++;
			for(int k=x-1;k>=0;k--){
				if(b[k]==a[j]){
					b[0]=a[j];
					for(int q=1;q<x;q++)b[q]=0;
					x=1;
				}
			}
		}
		for(int k=0;k<x;k++){
			c[b[k]++];
		}
		for(int k=0;k<m;k++){
			if(c[i]>0)d[i]++;
		}
	}
	if(m==1)cout<<2;
	else for(int i=0;i<m;i++)cout<<d[i]<<" ";
	return 0;
} 
