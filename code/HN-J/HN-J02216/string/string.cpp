#include<bits/stdc++.h>
using namespace std;
char d[2000001];
int main(){
	int a,b,c=1,f;
	char e;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		cin>>e;
		for(int i=c;i<=b;i++){
			d[i]==e;
		}
		c+=b;
	}
	
	if(c%2==0){
		for(int i=1;i<=c;i++){
			if(d[i]==d[c-i+1]){
				f++;
			}
		}
	
	}
	else{
		
		for(int i=1;i<=c;i++){
			if(i==c-i+1){
				
				break;
			}
			if(d[i]!=d[c+1-i]){
				f++;
			}
		}
	}
	cout<<f+1;
	
	return 0;
}
