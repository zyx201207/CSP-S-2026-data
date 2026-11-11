#include <iostream>
using namespace std;
long long n,m,a[500],k;
int main(){
	cin>>n>>m;
	while(a!=0){
	cin>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			a[i]=j;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			for(int j=i;j<n;j++){
				a[j]--;
			}
		}
		else{
		a[i+1]=k;
		break;
	}
	}
	
	}
	return 0;
}
