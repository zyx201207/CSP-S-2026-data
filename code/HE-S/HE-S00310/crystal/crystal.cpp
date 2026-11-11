#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,c;
	cin>>m;
	for(int i=1;i<=5;i++){
		cin>>a;
		if(m<=10){
			cout<<a;	
		}
		for(int j=0;j<=a;j++){
			c+=2;
			if(c==83){
				cout<<m;
			}
			else{
				int q=0;
				cin>>q;
				for(q=0;q<=i;q++){
					cout<<n;
				}
			}
		}
		
	}
	int x,y=100;
	cin>>x; 
	cout<<y;
	if(x==y){
		cout<<"100";
	}
	else{
		int w;
		cout<<m;
	}
	return 0;
} 
