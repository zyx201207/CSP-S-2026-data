#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int sum=0;
		
		for(int i=1;i<=a;i++){
			int b;
		string c;
		cin>>b>>c;
		for(int j=1;j<=b;j++)
		string 	c1=c1+c;
			        
           string s=s+c;
           
		 int mid=s.size()/2;
		 int w=false;
    for(int k=1;k<=mid;k++){
	if(s[mid+k]!=s[mid-k]){
        s[mid+k]=s[mid-k];
			w=true;
		}
	   }
	   if(w==true){
	   	sum++;
	   }	
		}
		
	
	cout<<sum-1;
	return 0;	

	}