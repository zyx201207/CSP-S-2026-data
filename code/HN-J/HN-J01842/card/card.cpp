#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b,man=-1;
	cin>>a>>b;
	long long a1[a];
	for(long long i=1;i<=a;i++){
		cin>>a1[i];}
	for(int i=1;i<=b;i++){
		long long a2[a];
		man=0;
		for(int j=i;j<=a-i;j++){
		 	a2[j-i+1]=a1[j];
		 	for(int x=1;x<j-i+1;x++){
		 		if(a2[j]==a[x]){
		 			for(int x1=1;x1<j-i+1;x1++) a2[x1]=-1; 
				 }
			 }
	}
	for(int g=1;g<=j;g++){
		if(a2[g]==i){
			man++;
		}
	}cout<<man<<" ";}
	
	  
	return 0;
}
