#include<iostream>
using namespace std;

int main(){
	int n,shu=1000000000;
	cin>>n;
	int a[n];
	char c[n];
	char*p=new char[shu];
	int p_=0;
	//∂®“Â 
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=0;j<a[i];j++){
			p[p_]=c[i];
			p_++;
		}
	}// ‰»Î
	 
	
	
	return 0;
} 
