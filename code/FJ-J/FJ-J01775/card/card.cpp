#include<bits/stdc++.h>
using namespace std;
int z[6]; 
int x[6];
int c[6]; 
int d[6];
int e[6];  
int main () {
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int u=0;
    for(int i=1;i<=a;i++){
    	cin>>z[i];
    	if(z[i]==1){
    		u++;
    	}
    }
    if(u==5){
    	cout<<5;
    }
    
	return 0;
}
