#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c=0,d=0,e=0,f=0;
	cin>>a>>b;
	int arr[a],arr1[a];
	for(int i=0;i<a;i++){
		cin>>arr[i];
	}
	for(int k=0;k<a;k++){
		for(int j=0;j<a;j++){
			if(arr[k]>=arr[j]){
				arr1[c]=arr[k]-arr[j];
				c++;
			}
		}
	
		for(int i=0;i<c;i++){
			for(int j=0;j<c-1;j++){
				if(arr1[j+1]<arr1[j]){
					swap(arr1[j+1],arr1[j]);
				}
				
			}
		}
		for(int i=0;i<c;i++){
			if(d<=b){
				d+=arr1[i];
				e++;
				
			}
		}
		
		c=0;
		f=max(e,f);
		e=0;
		d=0;
	}
	cout<<f<<endl;
	return 0;
}