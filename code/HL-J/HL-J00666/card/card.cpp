#include <bits/stdc++.h>
using namespace std;
int m,n,a[100],o=0,rst[100],rst2[100];


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for (int i=0;i<m+1;i++){
		rst2[i]=0;
	}
	
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			rst2[rst[j]]++;
			rst[j]=0;
		}
		for (int j=i;j<n;j++){
			for (int k=0;k<o;k++){
				if (rst[k]==a[j]){
					for (int x=0;x<k;x++){
						rst[x]=0;
					}
				}
				rst[o]=a[j];	 	
		}
	}
	for (int i=0;i<m;i++){
		cout<<rst2[i+1]<<" ";
	}

}
} 
