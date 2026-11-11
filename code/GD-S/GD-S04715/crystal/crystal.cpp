#include<iostream>
using namespace std;
long long n,m,a[5000099],ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(ans<=m){
			ans=a[j]-a[j-i]; 
			ans*=i;
			}
			else{
				cout << ans;
			}
		} 
	} 
	return 0;
} 
