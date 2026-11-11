#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c=0,d;
	cin>>a>>b;
	int arr[a],arr1[b],arr2[b];
	for(int i=0;i<a;i++){
		cin>>arr[i];
		
	}
	for(int i=0;i<b;i++){
		arr1[i]=0;
		arr2[i]=0;
	}
	
	for(int i=0;i<=a;i++){
		for(int j=i;j<=a;j++){
			arr1[c]=arr[j];
			
			for(int k=0;k<c-1;k++){
				if(arr1[c]==arr1[k]&&arr1[c]!=0){
					d=k;
				}
			}
			for(int k=d+1;k<c;k++){
				arr1[k]=0;
				c=d;
			}
			c++;
		}
		c=0;
		for(int j=0;j<c;j++){
			arr2[arr1[j]]++;
			
		}
	}
	for(int i=0;i<b;i++){
		cout<<arr2[i]<<' ';
	}
	return 0;
}
