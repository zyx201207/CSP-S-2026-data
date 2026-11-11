#include<bits/stdc++.h>
using namespace std;
int a[2000000];
char c[2000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<"0";
	}
	else{for(int i=0;i<1;i++){
		for(int j=0;j<n;j++){
				cin>>a[i]>>c[i];
			if( c[i]==c[i+1]){
			cout<<"0";
			break;
       	}
		}
	
		}
	
		
	}
	
	return 0;
}
