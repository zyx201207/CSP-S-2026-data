#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int z[200005];
int main()
{
	int c=1,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
 		for(int j=i;j<=n;j++){
 			if(b[j]==b[i]){
 				for(int k=i;k<j;k++){
 					b[k]=0;
				 }
				 continue;
			 }
		 }
		 for(int j=1;j<=m;j++){
		 	a[b[j]]++;
		 }
 	}
 	for(int i=1;i<=m;i++){
 		cout<<a[i]<<" ";
	 }
	
	return 0;	
} 
