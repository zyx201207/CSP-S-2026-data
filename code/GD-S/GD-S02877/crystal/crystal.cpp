#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[n];
	int sum=0,max=sum;
	
	for(int i=0;i<n;i++){
		for(int i=0;i<n;i++){
		    b[i]=a[i];
	    }
		int key=b[i];
		if(sum>max){
			max=sum;
		}
		sum=0;
		int mm=m;
		
		for(int j=0;j<=i;j++){
		    while(b[j]!=key){
		    	if(mm==0){
		    		break;
				}
				
		    	b[j]++;
		    	mm=mm-1;
			}
			if(b[j]==key){
			    sum++;	
			}
		}
	}
	cout<<max;
	return 0;
} 
