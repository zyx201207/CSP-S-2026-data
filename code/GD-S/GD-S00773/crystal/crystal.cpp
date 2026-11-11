#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[50010];
	int min;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		min=a[1];
		if(a[i]<min){
			min=a[i];
		}
		
		
	}
	return 0;
} 
