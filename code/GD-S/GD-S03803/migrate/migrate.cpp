#include<iostream>
using namespace std;
int problem(){
	long long dpl[5001][5001]={},dpw[5001][5001]={},is[5001]={};
	long long n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>is[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;is[j]-is[i]<=d;j++){
			dpl[i][j]=1;
			dpw[i][j]++;
		}
	}
	for(int i=2;i<n;i++){
		for(j=0;j<i;j++){
		}
	}
}
int main(){
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		
	}
	return 0;
}
