#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,n,m;
	char c[3],d[3];
	
	cin>>a>>c;
	cin>>b>>d;
	if(a == b){
		cout<<1;
		
	}else{
		cout<<0;
	}

		
	
	if(a == b&&c[0] == d[0]&&c[1] == d[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a == b&&c[0] == d[0]&&c[1] == d[1]){
		if(c[2] == 'A'||c[2] == 'B'||c[2] == 'C'&&d[2] == 'A'||d[2] == 'B'||d[2] == 'C'){
			cout<<1;
		}else if(c[2] == 'D'||c[2] == 'E'&&d[2] == 'D'||d[2] == 'E'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(a == b&&c[2]+1 == d[2]+0||c[2]-1 == d[2]+0&&c[0] == d[0]&&c[1] == d[1]){
			if(c[2] == 'C'&&d[2] == 'D'||c[2] == 'D'&&d[2] == 'C'){
				cout<<0;
			}else{
				cout<<1;
			}
		
		
		
	}else{
		cout<<0;
	}
	return 0;
} 
