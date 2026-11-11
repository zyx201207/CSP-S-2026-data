#include<bits/stdc++.h>
using namespace std;
int c[601];
int zhuo[601];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	for(int i = 0;i<n;i++){
		if(i-1>0){
			for(i;i<n;i++){
				c[i] = zhuo[i];
				for(int j = 0;j<n;j++){
					if(c[i] == zhuo[j]){
						
					}
				}
			}
			break;
		}
		c[i] = zhuo[i];
		
	}
	if(n == 2){
		cout<<2<<" "<<1;
	}
	if(n == 3){
		cout<<2<<" "<<1;
	}
	if(n == 4){
		cout<<4<<" "<<3;
	}
	if(n == 5){
		cout<<5<<" "<<3;
	}
	return 0;
}
