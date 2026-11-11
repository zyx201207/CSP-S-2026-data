#include<bits/stdc++.h>
using namespace std;
int n,b[1000000],sam[1000000]={0},k=0;
int ao(int d,int y,int z){
	
	if(d%2==1){
		if(y%2==1){
			sam[k]=pow(2,z)+sam[k];
			z++;
			
		}
	}
		
	if(d==0||y==0){
		sam[k]+=0;
		return 0;
	}
	
	ao(d/2,y/2,z);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			ao(b[j],b[j+1],0);
			cout<<sam[3];
			k++;
		
		} 
	}
	
	return 0;
}
