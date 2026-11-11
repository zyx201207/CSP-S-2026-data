#include <bits/stdc++.h>
using namespace std;
queue <int> a;
int n;

int main(){
	
	int m,b,r=0,z;
	cin>>n>>m;
	int t[n];
	for(int i=0;i<n;i++){
		cin>>b;
		a.push(b);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			bool q=0;
			 
			while(q!=1&&r<n){
			
				if(t[r]==a.front()){
					q=1;
					
					}
				r++;
			}
			if(q==1){
				for(int s=r;s<n;s++)t[s]=0;
				for(int s=0;s<n;s++){
					if(t[s]==a.front()){
					
						for(int e=s;e<n;e++){
							t[e]=t[e+1];
							t[e+1]=0;
						}
				
					}
				}

			}
			
		}
			

			
		
		
		
	}
		
		
	

	return 0;
}
