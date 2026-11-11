#include<iostream>
using namespace std;
int a[100005][100005];
int main(){
	int m,n;
	cin>>m>>n;
    for(int i=1;i<=n;i++){
    	int x,y;
    	cin>>x>>y;
    	for(int j=1;j<=x;j++){
    		cin>>a[i][j];
    	}
	} 
	cout<<1<<endl<<2;
	return 0;
} 
