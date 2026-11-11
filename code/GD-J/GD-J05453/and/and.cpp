#include<iostream>
using namespace std;
long long input[1000000]={0};
int main(){
	long long int m,n,ans=0,t=1;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>input[i];
		}
	for(int j=1;j<m;j++){
		for(int i=1;i<m;i++){
			if(input[i]<input[i+1]){
				swap(input[i],input[i+1]);
			}
		}
	}
	ans=input[1];
	for(int i=1;i<=n;i++){
		ans=(ans & input[i+1]); 
	}
	cout<<ans;
	return 0;
}
