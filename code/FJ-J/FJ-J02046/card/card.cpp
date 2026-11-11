#include<iostream>
using namespace std;
int n,m;
int a[100000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m=2){
		for (int i=1;i<=n;i++){
			cout<<1<<" ";
		}
	}
	return 0;
}
