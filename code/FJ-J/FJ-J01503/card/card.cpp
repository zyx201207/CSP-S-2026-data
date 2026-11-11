#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n],b[m],c[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		b[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[j]=a[j];
		}
		for(int j=i;j<n;j++){
			for(int k=i;k<j;k++){
				if(c[j]==c[k]&&c[j]!=0){
					for(int p=k;p<j;p++){
						c[p]=0;
					}
				}
			}
		}
		for(int j=i;j<n;j++){
			if(c[j]!=0) b[c[j]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
