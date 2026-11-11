#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005],b[100003]={0},c[100003]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k=0;	
		c[1000]={0};
		for(int j=i;j<n;j++){
			for(int t=0;t<k-1;t++){
				if(a[j]==c[t]){
					for(int r=t;r<k-1;r++){
						c[r]=0;
					}
					k=t;
					break;
				}
			}
			c[k++]=a[j];
		}
		for(int l=0;l<k;l++){
			if(c[l]<=m){
				b[c[l]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
} 

